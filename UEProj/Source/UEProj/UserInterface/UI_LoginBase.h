﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_LoginBase.generated.h"

class UTextBlock;
class UEditableText;
class UButton;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_LoginBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* ErrorHintText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* UsernameText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UTextBlock* PasswordText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UEditableText* UsernameEditText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UEditableText* PasswordEditText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UButton* ConfirmButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget, Category="UI_Elements"))
	UButton* CancelButton;

	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	bool Login();
	UFUNCTION(BlueprintCallable)
	FString GetUsername();
	UFUNCTION(BlueprintCallable)
	FString GetPassword();

	UFUNCTION(BlueprintCallable)
	void OnConfirmButtonClicked();
	UFUNCTION(BlueprintCallable)
	void OnCancelButtonClicked();
	
protected:
	bool Login(FString Username, FString Password);
	
	FTimerHandle ErrorDisplayDelayTimerHandle;
};