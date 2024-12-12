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
	
	void UpdateScore(int Points);
	int GetScore() const;
	// UI加载
	void ShowGameLoginUI(APlayerController* PlayerController);
	void ShowGameStartUI(APlayerController* PlayerController);
	void ShowGameLoadingUI(APlayerController* PlayerController);
	void ShowGameOverUI(APlayerController* PlayerController);
	static void EnablePlayer(APlayerController* PlayerController);
	static void DisablePlayer(APlayerController* PlayerController);
public:
	UFUNCTION(BlueprintCallable)
	void EndGame();
	UFUNCTION(BlueprintCallable)
	void StartGame();
	UFUNCTION(BlueprintCallable)
	void ResetGame();
	UFUNCTION(BlueprintCallable)
	void QuitGame();
	UFUNCTION(BlueprintCallable)
	void UpdateTime();
	UFUNCTION(BlueprintCallable)
	void UpdateAmmo();
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float Damage);
	UFUNCTION(BlueprintCallable)
	void SetCurrentWidget(TSubclassOf<UUserWidget> NewWidget, APlayerController* PlayerController=nullptr);
	UFUNCTION(BlueprintCallable)
	UUserWidget* GetCurrentWidget();
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetLeftAmmo() { return LeftAmmo; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetLeftHealth() { return LeftHealth; }
	
	// 地图生成范围
	UPROPERTY(EditAnywhere, Category = "Game Rules|Spawn")
	FVector SpawnAreaMin = FVector(50.0f, 50.0f, 50.0f);  // 区域最小值
	UPROPERTY(EditAnywhere, Category = "Game Rules|Spawn")
	FVector SpawnAreaMax = FVector(2850.0f, 3350.0f, 500.0f);    // 区域最大值
	// 方块生成
	UPROPERTY(EditAnywhere, Category="Game Rules|Cubes")
	int TotalCubes = 20;
	UPROPERTY(EditAnywhere, Category = "Game Rules|Cubes")
	int ImportantCubeCount = 5;
	UPROPERTY(EditAnywhere, Category="Game Rules|Cubes")
	TSubclassOf<AActor> CubeClass;
	// UI类
	UPROPERTY(EditAnywhere, Category = "Game Rules|UI")
	TSubclassOf<UUserWidget> GameStartMenuWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Game Rules|UI")
	TSubclassOf<UUserWidget> GameEndMenuWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Game Rules|UI")
	TSubclassOf<UUserWidget> GameLoadingWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Game Rules|UI")
	TSubclassOf<UUserWidget> GameHUDWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Game Rules|UI")
	TSubclassOf<UUserWidget> GameLoginWidgetClass;
	// 游戏时间
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	float TimeLimit = 15.0f;
	// 游戏弹药
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int FullAmmo = 40;
	// 玩家血量
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	float FullHealth = 100.0f;
	// 游戏得分
	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int TotalScore = 0;
	// 材质资源
	UPROPERTY(EditAnywhere, Category = "Game Rules|Cubes|Material")
	UMaterialInterface* NormalMaterial = nullptr;
	UPROPERTY(EditAnywhere, Category = "Game Rules|Cubes|Material")
	UMaterialInterface* SpecialMaterial = nullptr;
protected:
	// 方块生成
	FVector GetRandomSpawnLocation(); // 获得随机生成位置的函数
	bool IsLocationValid(FVector Location,
	                     const TArray<FVector>& ExistingLocations, float MinDistance);
	void SpawnCubes();
	// 分数显示
	void LogScores();	// 日志打印分数
	void LoadingFinished();

	FTimerHandle TickTimerHandle;
	FTimerHandle LoadingHandle;
	UUserWidget* CurrentWidget;
	bool IsGameStart = true;
	bool IsGameOver = false;

	int LoadingPercent = 0;
	float LeftTime = TimeLimit;
	int LeftAmmo = FullAmmo;
	int LeftHealth = FullHealth;
};



