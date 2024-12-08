// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_HUDBase.h"

#include "Components/TextBlock.h"

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


