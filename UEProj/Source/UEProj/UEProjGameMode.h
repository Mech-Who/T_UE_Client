// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UEProjGameMode.generated.h"

UCLASS(minimalapi)
class AUEProjGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUEProjGameMode();

	virtual void BeginPlay() override;
	
	// void AddScore(int Points, APlayerController* Player);
	// void RemoveScore(int Points, APlayerController* Player);
	void AddScore(int Points);
	void RemoveScore(int Points);
	int GetScore() const;

	void EndGame();
	void ShowTime();

private:
	void SpawnCubes();
	void LogScores();

	FTimerHandle GameTimerHandle;
	FTimerHandle TickTimerHandle;
	TMap<APlayerController*, int> PlayerScores;
	// Total Cubes
	UPROPERTY(EditAnywhere, Category="Game Rules")
	int TotalCubes = 20;
	// Valuable Cube
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int ImportantCubeCount = 5;
	// Game Time
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	double TimeLimit = 60.0f;
	double LeftTime = 60.f;
private:
	int TotalScore;
};



