// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

#include "UI_EndMenuBase.h"

#include "UI_HUDBase.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/GameSession.h"
#include "UEProj/GameSetting/UEProjGameMode.h"

void UUI_EndMenuBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	auto PlayerController = GetOwningPlayer();
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	if (ContinueButton)
	{
		ContinueButton->OnClicked.AddDynamic(this, &UUI_EndMenuBase::OnContinueButtonClicked);
	}
	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UUI_EndMenuBase::OnExitButtonClicked);
	}
}


void UUI_EndMenuBase::UpdateScore(int NewScore)
{
	if (NewScore < 0)
	{
		UE_LOG(LogTemp, Error, TEXT("[ERROR] Score is negative!"));
		return;
	}
	if (ScoreValueText)
	{
		ScoreValueText->SetText(FText::FromString(FString::FromInt(NewScore)));
	}
}

void UUI_EndMenuBase::OnContinueButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("[INFO] Continue button clicked"));
	auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
	// auto LevelName = GetWorld()->GetCurrentLevel()->GetName();
	// UGameplayStatics::OpenLevel(GetWorld(), FName(*LevelName), true);
	RemoveFromParent();
	if (auto PlayerController = GetOwningPlayer())
	{
		GameMode->EnablePlayer(PlayerController);
		GameMode->SetCurrentWidget(GameMode->GameHUDWidgetClass, PlayerController);
	}
	GameMode->ResetGame();
	GameMode->StartGame();
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void UUI_EndMenuBase::OnExitButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("[INFO] Continue button clicked"));
	auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
	auto PlayerController = GetOwningPlayer();
	GameMode->ShowGameLoginUI(PlayerController);
	RemoveFromParent();
}
