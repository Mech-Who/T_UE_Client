// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Slate/SGameLayerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "UEProjGameMode.h"
#include "UEProj/ABP_Cube.h"
#include "UEProj/UEProjCharacter.h"
#include "UEProj/utils.h"
#include "UEProj/UserInterface/UI_HUDBase.h"

AUEProjGameMode::AUEProjGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// 加载普通材质
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> NormalMat(TEXT("/Game/LevelPrototyping/Materials/M_Solid"));
	if (NormalMat.Succeeded()) {
		NormalMaterial = NormalMat.Object;
	}

	// 加载特殊材质
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> SpecialMat(TEXT("/Game/LevelPrototyping/Materials/MI_Solid_Blue"));
	if (SpecialMat.Succeeded()) {
		SpecialMaterial = SpecialMat.Object;
	}

	// 加载 UI_Login
	static ConstructorHelpers::FClassFinder<UUserWidget> GameLoginWidgetFinder(TEXT("/Game/UserInterface/UI_Login"));
	if (GameLoginWidgetFinder.Succeeded()) {
		GameLoginWidgetClass = GameLoginWidgetFinder.Class;
	} else {
		UE_LOG(LogTemp, Error, TEXT("Failed to load GameLoginWidgetFinder!"));
	}
	// 加载 UI_StartMenu
	static ConstructorHelpers::FClassFinder<UUserWidget> GameStartWidgetFinder(TEXT("/Game/UserInterface/UI_StartMenu"));
	if (GameStartWidgetFinder.Succeeded()) {
		GameStartMenuWidgetClass = GameStartWidgetFinder.Class;
	} else {
		UE_LOG(LogTemp, Error, TEXT("Failed to load GameStartWidgetClass!"));
	}
	// 加载 UI_Loading
	static ConstructorHelpers::FClassFinder<UUserWidget> GameLoadingWidgetFinder(TEXT("/Game/UserInterface/UI_Loading"));
	if (GameLoadingWidgetFinder.Succeeded()) {
		GameLoadingWidgetClass = GameLoadingWidgetFinder.Class;
	} else {
		UE_LOG(LogTemp, Error, TEXT("Failed to load GameLoadingWidgetFinder!"));
	}
	// 加载 UI_HUD
	static ConstructorHelpers::FClassFinder<UUserWidget> GameHUDWidgetFinder(TEXT("/Game/UserInterface/UI_hud"));
	if (GameHUDWidgetFinder.Succeeded()) {
		GameHUDWidgetClass = GameHUDWidgetFinder.Class;
	} else {
		UE_LOG(LogTemp, Error, TEXT("Failed to load GameHUDWidgetFinder!"));
	}
	// 加载 UI_EndMenu
	static ConstructorHelpers::FClassFinder<UUserWidget> GameOverWidgetFinder(TEXT("/Game/UserInterface/UI_EndMenu"));
	if (GameOverWidgetFinder.Succeeded()) {
		GameEndMenuWidgetClass = GameOverWidgetFinder.Class;
	} else {
		UE_LOG(LogTemp, Error, TEXT("Failed to load GameOverWidgetClass!"));
	}
	
	CubeClass = AABP_Cube::StaticClass();
}

// 初始化
void AUEProjGameMode::BeginPlay() {
	Super::BeginPlay();

	auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	this->ShowGameLoginUI(PlayerController);
	
	// 1. 游戏准备
	this->ResetGame();
}

void AUEProjGameMode::ShowGameLoginUI(APlayerController* PlayerController) {
	if (GameLoginWidgetClass) {
		// 禁用玩家输入并创建UI组件
		DisablePlayer(PlayerController);
		SetCurrentWidget(GameLoginWidgetClass, PlayerController);
	} else {
		UE_LOG(LogTemp, Error, TEXT("GameLoginWidgetClass is not set!"));
	}
}

void AUEProjGameMode::ShowGameStartUI(APlayerController* PlayerController) {
	if (GameStartMenuWidgetClass) {
		// 禁用玩家输入并创建UI组件
		DisablePlayer(PlayerController);
		SetCurrentWidget(GameStartMenuWidgetClass, PlayerController);
	} else {
		UE_LOG(LogTemp, Error, TEXT("GameStartWidgetClass is not set!"));
	}
}

void AUEProjGameMode::ShowGameLoadingUI(APlayerController* PlayerController) {
	if (GameLoadingWidgetClass) {
		// 禁用玩家输入并创建UI组件
		DisablePlayer(PlayerController);
		SetCurrentWidget(GameLoadingWidgetClass, PlayerController);
	} else {
		UE_LOG(LogTemp, Error, TEXT("GameLoadingWidgetClass is not set!"));
	}
	
	GetWorldTimerManager().SetTimer(LoadingHandle,
		[this]()
		{
			if (this->CurrentWidget)
			{
				LoadingPercent += 25;
				// 在这里可以通过接口或绑定更新分数显示
				UFunction* UpdateProgressFunction = this->CurrentWidget->FindFunction(FName("UpdateProgress"));
				if (UpdateProgressFunction) {
					FFrame::KismetExecutionMessage(TEXT("Updating Progress on UI"), ELogVerbosity::Log);
					CurrentWidget->ProcessEvent(UpdateProgressFunction, &this->LoadingPercent);
				}
			}
			if (LoadingPercent > 100)
			{
				UE_LOG(LogTemp, Display, TEXT("Loading finished!"));
				LoadingFinished();
				// 清除定时器
				if (GetWorldTimerManager().IsTimerActive(LoadingHandle)) {
					GetWorldTimerManager().ClearTimer(LoadingHandle);
				}
			}
			
		}, 1, true);
}

void AUEProjGameMode::ShowGameOverUI(APlayerController* PlayerController) {
	if (GameEndMenuWidgetClass) {
		// 禁用玩家输入并创建UI组件
		DisablePlayer(PlayerController);
		SetCurrentWidget(GameEndMenuWidgetClass, PlayerController);
		if (CurrentWidget) {
			// 在这里可以通过接口或绑定更新分数显示
			UFunction* SetScoreFunction = CurrentWidget->FindFunction(FName("SetTotalScore"));
			if (SetScoreFunction) {
				FFrame::KismetExecutionMessage(TEXT("Updating Score on UI"), ELogVerbosity::Log);
				CurrentWidget->ProcessEvent(SetScoreFunction, &this->TotalScore);
			}
		}
	} else {
		UE_LOG(LogTemp, Error, TEXT("GameOverWidgetClass is not set!"));
	}
}

void AUEProjGameMode::UpdateScore(int Points)
{
	if (!this->IsGameOver)
	{
		this->TotalScore += Points;
		// Utils::display_display(FString::Printf(TEXT("Current Score: %d"), this->TotalScore));
		// 在这里可以通过接口或绑定更新分数显示
		if (this->CurrentWidget)
		{
			auto HUDWidget = Cast<UUI_HUDBase>(this->CurrentWidget);
			HUDWidget->UpdateScore(this->TotalScore);
		}else
		{
			UE_LOG(LogTemp, Error, TEXT("CurrentWidget is not set!"));
		}
	}
}

int AUEProjGameMode::GetScore() const
{
	return this->TotalScore;
}

bool AUEProjGameMode::IsLocationValid(FVector Location,
	const TArray<FVector>& ExistingLocations,
	float MinDistance)
{
	for (const FVector& ExistingLocation : ExistingLocations) {
		if (FVector::Dist(Location, ExistingLocation) < MinDistance) {
			return false;
		}
	}
	return true;
}

FVector AUEProjGameMode::GetRandomSpawnLocation()
{
	// 在指定区域内随机生成坐标
	return UKismetMathLibrary::RandomPointInBoundingBox((SpawnAreaMin + SpawnAreaMax) / 2, (SpawnAreaMax - SpawnAreaMin) / 2);
}

// 生成Cubes
void AUEProjGameMode::SpawnCubes() {
	// DEBUG: 可视化生成区域
	// DrawDebugBox(GetWorld(), (SpawnAreaMin + SpawnAreaMax) / 2, (SpawnAreaMax - SpawnAreaMin) / 2, FColor::Green, true, 10.0f);
	// TODO: 设置AActor作为生成点坐标，但是AActor如何设置！
	if (!CubeClass) {
		UE_LOG(LogTemp, Warning, TEXT("CubeClass is not set!"));
		return;
	}

	TArray<FVector> SpawnedLocations;
	for (int i = 0; i < TotalCubes; i++) {
		// 随机生成位置
		FVector SpawnLocation = GetRandomSpawnLocation();
		while (!IsLocationValid(SpawnLocation, SpawnedLocations, 100.0f)) {
			SpawnLocation = GetRandomSpawnLocation();
		}
		SpawnedLocations.Add(SpawnLocation);
		
		// 随机生成旋转角度
		FRotator SpawnRotation = FRotator(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

		// 生成方块实例
		AABP_Cube* Cube = GetWorld()->SpawnActor<AABP_Cube>(CubeClass, SpawnLocation, SpawnRotation);
		// Debug Print Log
		if (Cube)
		{
			UE_LOG(LogTemp, Log, TEXT("Spawned cube at location: %s"), *SpawnLocation.ToString());
		}
		
		// 设置重要目标
		if (i < ImportantCubeCount) {
			if (SpecialMaterial)
				Cube->BeImportant(Cube->ScoreValue*2, SpecialMaterial);
			else
				Cube->BeImportant(Cube->ScoreValue*2);
		}else
		{
			if (NormalMaterial)
				Cube->SetMaterial(NormalMaterial);
		}
	}
}

void AUEProjGameMode::QuitGame()
{
	// 退出游戏
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}


// 游戏结束
void AUEProjGameMode::EndGame() {
	// Utils::display_display(FString(TEXT("===== Game Over =====")));
	// 修改游戏状态
	this->IsGameStart = false;
	this->IsGameOver = true;
	
	// 获取所有 ABP_Cube 类型的 Actor
	TArray<AActor*> FoundCubes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AABP_Cube::StaticClass(), FoundCubes);
	// 遍历并销毁每个 Cube
	for (AActor* Cube : FoundCubes) {
		if (Cube) {
			UE_LOG(LogTemp, Log, TEXT("Destroying Cube: %s"), *Cube->GetName());
			Cube->Destroy();
		}
	}

	this->CurrentWidget->RemoveFromParent();
	auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	this->ShowGameOverUI(PlayerController);
	
	// 打印得分
	// LogScores();

	// 假设已有定时器句柄 TimerHandle
	if (GetWorldTimerManager().IsTimerActive(TickTimerHandle)) {
		GetWorldTimerManager().ClearTimer(TickTimerHandle);
	}
}

// 游戏开始
void AUEProjGameMode::StartGame()
{
	this->IsGameStart = true;
	this->IsGameOver = false;
	// 启动游戏定时器
	GetWorldTimerManager().SetTimer(this->TickTimerHandle, this,
		&AUEProjGameMode::UpdateTime, 1, true);
	// 生成方块
	SpawnCubes();
}

// 游戏重置
void AUEProjGameMode::ResetGame()
{
	this->IsGameStart = false;
	this->IsGameOver = false;
	this->LeftTime = this->TimeLimit;
	this->TotalScore = 0;
	UE_LOG(LogTemp, Display,
		TEXT("Game Reset: LeftTime: %f s, TotalScore: %d"),
		LeftTime, TotalScore);
}

// 显示剩余时间
void AUEProjGameMode::UpdateTime()
{
	--LeftTime;
	if (this->CurrentWidget)
	{
		auto HUDWidget = Cast<UUI_HUDBase>(this->CurrentWidget);
		HUDWidget->UpdateTime(this->LeftTime);
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("CurrentWidget is not set!"));
	}
	if (this->LeftTime <= 0)
	{
		EndGame();
	}
}

// 打印积分日志
void AUEProjGameMode::LogScores() {
	// for (auto& Pair : PlayerScores) {
	// 	APlayerController* Player = Pair.Key;
	// 	int Score = Pair.Value;
	//
	// 	UE_LOG(LogTemp, Display, TEXT("Player %s scored: %d"), *Player->GetName(), Score);
	// }
	Utils::display_display(FString::Printf(TEXT("Total Score: %d"), TotalScore));
	Utils::display_display(FString(TEXT("===== Statistic Over =====")));
}

void AUEProjGameMode::LoadingFinished()
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		auto PlayerController = CurrentWidget->GetOwningPlayer();
		EnablePlayer(PlayerController);
		SetCurrentWidget(GameHUDWidgetClass, PlayerController);
		UE_LOG(LogTemp, Display, TEXT("Loading finished"));
	}

}

void AUEProjGameMode::SetCurrentWidget(TSubclassOf<UUserWidget> NewWidget, APlayerController* PlayerController)
{	
	CurrentWidget = UWidgetBlueprintLibrary::Create(GetWorld(), NewWidget, PlayerController);
	if (CurrentWidget)
	{
		CurrentWidget->AddToViewport();
	}
}

void AUEProjGameMode::EnablePlayer(APlayerController* PlayerController)
{
	if (PlayerController)
	{
		PlayerController->EnableInput(PlayerController);
		PlayerController->SetShowMouseCursor(false);
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
}

void AUEProjGameMode::DisablePlayer(APlayerController* PlayerController)
{
	if (PlayerController)
	{
		PlayerController->DisableInput(PlayerController);
		PlayerController->SetShowMouseCursor(true);
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
}

