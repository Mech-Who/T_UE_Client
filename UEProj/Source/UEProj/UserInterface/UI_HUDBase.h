// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI_CrossHairBase.h"
#include "Blueprint/UserWidget.h"
#include "UI_HUDBase.generated.h"

class UTextBlock;
class UProgressBar;

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
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UProgressBar* HealthProgressBar;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UTextBlock* LeftHealthText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UTextBlock* FullHealthText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UTextBlock* LeftAmmoText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UTextBlock* FullAmmoText;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UUI_CrossHairBase* CrossHair;

	UFUNCTION(BlueprintCallable)
	void UpdateScore(int NewScore);
	UFUNCTION(BlueprintCallable)
	void UpdateTime(int NewTime);
	UFUNCTION(BlueprintCallable)
	void UpdateAmmo(int NewAmmo);
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float NewHealth);
	UFUNCTION(BlueprintCallable)
	float GetFullHealth(){ return FullHealth; }
	UFUNCTION(BlueprintCallable)
	void SetFullHealth(float Value);
	UFUNCTION(BlueprintCallable)
	float GetFullAmmo(){ return FullAmmo; }
	UFUNCTION(BlueprintCallable)
	void SetFullAmmo(float Value);
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UUI_CrossHairBase* GetCrossHair(){ return CrossHair; };

	
	virtual void NativeOnInitialized() override;
protected:
	float FullHealth = 100.0f;
	int FullAmmo = 40;
};
