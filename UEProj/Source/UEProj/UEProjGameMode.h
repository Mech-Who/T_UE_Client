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

	UFUNCTION(BlueprintCallable)
	void EndGame();
	UFUNCTION(BlueprintCallable)
	void StartGame();
	UFUNCTION(BlueprintCallable)
	void ResetGame();
	UFUNCTION(BlueprintCallable)
	void QuitGame();
	UFUNCTION(BlueprintCallable)
	void ShowTime();
	UFUNCTION(BlueprintCallable)
	void SetScoreWidget(UUserWidget *widget);

private:
	bool IsLocationValid(FVector Location,
		const TArray<FVector>& ExistingLocations, float MinDistance);
	void SpawnCubes();
	void ShowGameStartUI();
	void ShowGameOverUI();
	void LogScores();

	// 随机生成位置的函数
	FVector GetRandomSpawnLocation();

	// 地图生成范围
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	FVector SpawnAreaMin = FVector(50.0f, 50.0f, 50.0f);  // 区域最小值

	UPROPERTY(EditAnywhere, Category = "Game Rules")
	FVector SpawnAreaMax = FVector(2850.0f, 3350.0f, 500.0f);    // 区域最大值
	
	FTimerHandle TickTimerHandle;
	TMap<APlayerController*, int> PlayerScores;
	// Total Cubes
	UPROPERTY(EditAnywhere, Category="Game Rules")
	int TotalCubes = 20;
	UPROPERTY(EditAnywhere, Category="Game Rules")
	TSubclassOf<AActor> CubeClass;
	// UI 资源
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> GameStartWidgetClass;
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;
	// Valuable Cube
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int ImportantCubeCount = 5;
	// Game Time
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	double TimeLimit = 15.0f;
	double LeftTime = TimeLimit;
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int TotalScore = 0;
	// 材质资源
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* NormalMaterial = nullptr;
	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* SpecialMaterial = nullptr;

	// 当前 UI 实例
	UUserWidget* CurrentWidget;
	UUserWidget* ScoreWidget;

	bool IsGameStart = true;
	bool IsGameOver = false;
};



