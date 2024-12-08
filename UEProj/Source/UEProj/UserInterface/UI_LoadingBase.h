// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI_LoadingBase.generated.h"

class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_LoadingBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeOnInitialized() override;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* LoadingText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* LoadingProgressText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UProgressBar* LoadingProgress;
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnim, Category="UI_Elements"))
	UWidgetAnimation* LoadingZoomInAndOut;

	UFUNCTION(BlueprintCallable)
	void UpdateProgress(int Percent);
	
protected:
	void ProgressFinished();
};
