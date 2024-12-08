// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_StartMenuBase.generated.h"

class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_StartMenuBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* StartButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* SettingButton;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UButton* ExitButton;

	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	void OnStartButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnSettingButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnExitButtonClicked();
	
protected:
};
