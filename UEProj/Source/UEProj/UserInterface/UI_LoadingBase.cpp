// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_LoadingBase.h"

#include "FindInBlueprints.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UUI_LoadingBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (LoadingZoomInAndOut)
	{
		PlayAnimation(LoadingZoomInAndOut, 0, 0, EUMGSequencePlayMode::PingPong);
	}
}

void UUI_LoadingBase::UpdateProgress(int Percent)
{
	if (Percent > 100 || Percent < 0)
	{
		LoadingProgress->SetPercent(1.0f);
		LoadingProgressText->SetText(FText::FromString(FString(TEXT("100%"))));
		UE_LOG(LogTemp, Error, TEXT("Loading progress update error"));
		return;
	}
	LoadingProgress->SetPercent(Percent / FullLoading);
	LoadingProgressText->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), Percent)));
	UE_LOG(LogTemp, Display, TEXT("Loading progress update to '%d' success"), Percent);
	if (Percent >= 100)
	{
		StopAnimation(LoadingZoomInAndOut);
	}
}

