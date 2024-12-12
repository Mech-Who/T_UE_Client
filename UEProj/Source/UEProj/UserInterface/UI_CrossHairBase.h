// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_CrossHairBase.generated.h"

class UBorder;
class UWidgetAnimation;

/**
 * 
 */
UCLASS()
class UEPROJ_API UUI_CrossHairBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UBorder* UpBorder;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UBorder* DownBorder;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UBorder* LeftBorder;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UBorder* RightBorder;
	UPROPERTY(BlueprintReadOnly, Transient, meta=(BindWidgetAnimOptional))
	UWidgetAnimation* ExpandCross;


	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	void OnFire();
};
