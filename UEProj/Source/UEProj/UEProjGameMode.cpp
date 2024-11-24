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
	CubeClass = AABP_Cube::StaticClass();
}

// 初始化
void AUEProjGameMode::BeginPlay() {
	Super::BeginPlay();

	// 1. 游戏准备
	// TODO: Spawn解决后再启用

	// 2. 游戏开始
	// 启动游戏定时器
	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AUEProjGameMode::EndGame, TimeLimit, false);
	GetWorldTimerManager().SetTimer(TickTimerHandle, this, &AUEProjGameMode::ShowTime, 1, true);
	// 生成方块
	SpawnCubes();
	
	// 3. 游戏结束
	// TODO
}

// void AUEProjGameMode::AddScore(int Points, APlayerController* Player)
void AUEProjGameMode::AddScore(int Points)
{
	// if (PlayerScores.Contains(Player)) {
	// 	PlayerScores[Player] += Points;
	// } else {
	// 	PlayerScores.Add(Player, Points);
	// }
	TotalScore += Points;
	UE_LOG(LogTemp, Log, TEXT("Current Score: %d"), TotalScore);
	FString msg = FString::Printf(TEXT("Add Score: %d, Current Score: %d"), Points, TotalScore);
	Utils::display(msg);
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
	TotalScore -= Points;
	UE_LOG(LogTemp, Log, TEXT("Current Score: %d"), TotalScore);
	FString msg = FString::Printf(TEXT("Current Score: %d"), TotalScore);
	Utils::display(msg);
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
			Cube->IsImportant = true;  // 标记为重要目标
			Cube->ScoreValue *= 2;    // 双倍积分
		}
	}
}

// 游戏结束
void AUEProjGameMode::EndGame() {
	// 停止游戏逻辑（如停止生成子弹）
	LogScores();
	// 假设已有定时器句柄 TimerHandle
	if (GetWorldTimerManager().IsTimerActive(TickTimerHandle)) {
		GetWorldTimerManager().ClearTimer(TickTimerHandle);
		UE_LOG(LogTemp, Log, TEXT("Timer has been canceled."));
		FString msg = FString("Timer has been canceled.");
		Utils::display(msg);
	}
}

void AUEProjGameMode::ShowTime()
{
	UE_LOG(LogTemp, Log, TEXT("Tik tok: %f"), LeftTime);
	FString msg = FString::Printf(TEXT("Tik tok: %f"), LeftTime);
	Utils::display(msg);
	--LeftTime;
}

// 打印积分日志
void AUEProjGameMode::LogScores() {
	// for (auto& Pair : PlayerScores) {
	// 	APlayerController* Player = Pair.Key;
	// 	int Score = Pair.Value;
	//
	// 	UE_LOG(LogTemp, Log, TEXT("Player %s scored: %d"), *Player->GetName(), Score);
	// }
	UE_LOG(LogTemp, Log, TEXT("Total Score: %d"), TotalScore);
	FString msg = FString::Printf(TEXT("Total Score: %d"), TotalScore);
	Utils::display(msg);
}


