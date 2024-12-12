// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_HUDBase.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UUI_HUDBase::UpdateScore(int NewScore)
{
	FString NewScoreText = FString::Printf(TEXT("Score: %d"), NewScore);
	ScoreText->SetText(FText::FromString(NewScoreText));
}

void UUI_HUDBase::UpdateTime(int NewTime)
{
	FString NewTimeText = FString::Printf(TEXT("Time: %d s"), NewTime);
	TimeText->SetText(FText::FromString(NewTimeText));
}

void UUI_HUDBase::UpdateAmmo(int NewAmmo)
{
	FString NewAmmoText = FString::Printf(TEXT("%d"), NewAmmo);
	LeftAmmoText->SetText(FText::FromString(NewAmmoText));
}

void UUI_HUDBase::UpdateHealth(float NewHealth)
{
	if (NewHealth > 100 || NewHealth < 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Health update error"));
		return;
	}
	FString NewHealthText = FString::Printf(TEXT("%.1f"), NewHealth);
	LeftHealthText->SetText(FText::FromString(NewHealthText));
	HealthProgressBar->SetPercent(NewHealth / FullHealth);
	UE_LOG(LogTemp, Display, TEXT("Health update to '%.1f/%.1f' success"), NewHealth, FullHealth);
}

inline void UUI_HUDBase::SetFullHealth(float Value)
{
	FullHealth = Value;
	FString HealthText = FString::Printf(TEXT("%.1f"), FullHealth);
	FullHealthText->SetText(FText::FromString(HealthText));
}

void UUI_HUDBase::SetFullAmmo(float Value)
{
	FullAmmo = Value;
	FString AmmoText = FString::Printf(TEXT("%d"), FullAmmo);
	FullAmmoText->SetText(FText::FromString(AmmoText));
}


void UUI_HUDBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	SetFullAmmo(FullAmmo);
	SetFullHealth(FullHealth);
}