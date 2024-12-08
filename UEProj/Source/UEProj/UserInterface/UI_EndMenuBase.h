// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "UI_EndMenuBase.generated.h"

class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_EndMenuBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* ContinueButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* ExitButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* ScoreValueText;

	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateScore(int NewScore);
	
	UFUNCTION(BlueprintCallable)
	void OnContinueButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnExitButtonClicked();

protected:
};
