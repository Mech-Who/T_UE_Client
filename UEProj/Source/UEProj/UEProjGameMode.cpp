// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEProjGameMode.h"
#include "ABP_Cube.h"
#include "UEProjCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Slate/SGameLayerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "utils.h"

AUEProjGameMode::AUEProjGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

// 初始化
void AUEProjGameMode::BeginPlay() {
	Super::BeginPlay();

	// TODO: Spawn解决后再启用
	// 生成方块
	// SpawnCubes();

	// 启动游戏定时器
	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AUEProjGameMode::EndGame, TimeLimit, false);
	GetWorldTimerManager().SetTimer(TickTimerHandle, this, &AUEProjGameMode::ShowTime, 1, true);
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
	FString msg = FString::Printf(TEXT("Current Score: %d"), TotalScore);
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

void AUEProjGameMode::SpawnCubes() {
	// TODO: 设置AActor作为生成点坐标，但是AActor如何设置！
	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("CubeSpawnPoint"), SpawnPoints);

	for (int i = 0; i < TotalCubes; i++) {
		FVector Location = SpawnPoints[FMath::RandRange(0, SpawnPoints.Num() - 1)]->GetActorLocation();
		FRotator Rotation = FRotator::ZeroRotator;

		// 生成方块实例
		auto Cube = GetWorld()->SpawnActor<AABP_Cube>(AABP_Cube::StaticClass(), Location, Rotation);

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


