// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_HUDBase.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_HUDBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* ScoreText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* TimeText;

	UFUNCTION(BlueprintCallable)
	void UpdateScore(int NewScore);
	UFUNCTION(BlueprintCallable)
	void UpdateTime(int NewTime);
	
protected:
};
