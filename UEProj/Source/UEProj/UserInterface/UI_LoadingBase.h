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
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* LoadingText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* LoadingProgressText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* LoadingProgress;
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* LoadingZoomInAndOut;

	UFUNCTION(BlueprintCallable)
	void UpdateProgress(int Percent);
	UFUNCTION(BlueprintCallable)
	float GetFullLoading(){ return FullLoading;}
	UFUNCTION(BlueprintCallable)
	void SetFullLoading(float Value) { FullLoading = Value;}
protected:
	float FullLoading = 100.0f;
};
