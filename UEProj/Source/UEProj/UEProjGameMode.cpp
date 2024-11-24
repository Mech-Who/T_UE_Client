// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEProjGameMode.h"
#include "ABP_Cube.h"
#include "UEProjCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Slate/SGameLayerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "utils.h"
#include "Kismet/KismetMathLibrary.h"

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
	
	CubeClass = AABP_Cube::StaticClass();
}

// 初始化
void AUEProjGameMode::BeginPlay() {
	Super::BeginPlay();

	// 1. 游戏准备
	this->ResetGame();
	Utils::display_display(FString(TEXT("===== Game Ready =====")));
}

// void AUEProjGameMode::AddScore(int Points, APlayerController* Player)
void AUEProjGameMode::AddScore(int Points)
{
	// if (PlayerScores.Contains(Player)) {
	// 	PlayerScores[Player] += Points;
	// } else {
	// 	PlayerScores.Add(Player, Points);
	// }
	if (!this->IsGameOver)
	{
		this->TotalScore += Points;
		Utils::display_display(FString::Printf(TEXT("Current Score: %d"), this->TotalScore));
	}
}

// void AUEProjGameMode::RemoveScore(int Points, APlayerController* Player)
void AUEProjGameMode::RemoveScore(int Points)
{
	// if (PlayerScores.Contains(Player))
	// {
	// 	PlayerScores[Player] -= Points;
	// }else
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("Error Player, Current Score: %d"), TotalScore);
	// 	return;
	// }
	if (!this->IsGameOver)
	{
		this->TotalScore -= Points;
		Utils::display_display(FString::Printf(TEXT("Current Score: %d"), this->TotalScore));
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
	// 可视化生成区域
	DrawDebugBox(GetWorld(), (SpawnAreaMin + SpawnAreaMax) / 2, (SpawnAreaMax - SpawnAreaMin) / 2, FColor::Green, true, 10.0f);
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

// 游戏结束
void AUEProjGameMode::EndGame() {
	Utils::display_display(FString(TEXT("===== Game Over =====")));
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

	// 打印得分
	LogScores();

	// 假设已有定时器句柄 TimerHandle
	if (GetWorldTimerManager().IsTimerActive(TickTimerHandle)) {
		GetWorldTimerManager().ClearTimer(TickTimerHandle);
		Utils::display_display(FString(TEXT("Time is up!")));
	}
}

// 游戏开始
void AUEProjGameMode::StartGame()
{
	this->IsGameStart = true;
	this->IsGameOver = false;
	// 启动游戏定时器
	GetWorldTimerManager().SetTimer(this->GameTimerHandle, this,
		&AUEProjGameMode::EndGame, this->TimeLimit, false);
	GetWorldTimerManager().SetTimer(this->TickTimerHandle, this,
		&AUEProjGameMode::ShowTime, 1, true);
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
}

// 显示剩余时间
void AUEProjGameMode::ShowTime()
{
	Utils::display_display(FString::Printf(TEXT("Tik tok: %.1f s"), LeftTime));
	--LeftTime;
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


