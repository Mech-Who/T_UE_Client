// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "UI_StartMenuBase.h"

#include "UI_HUDBase.h"
#include "UEProj/GameSetting/UEProjGameMode.h"

void UUI_StartMenuBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &UUI_StartMenuBase::OnStartButtonClicked);	
	}
	if (SettingButton)
	{
		SettingButton->OnClicked.AddDynamic(this, &UUI_StartMenuBase::OnSettingButtonClicked);
	}
	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UUI_StartMenuBase::OnExitButtonClicked);
	}
}
	
void UUI_StartMenuBase::OnStartButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("Start button clicked"));
	auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->ResetGame();
	GameMode->ShowGameLoadingUI(GetOwningPlayer());
	RemoveFromParent();
}

void UUI_StartMenuBase::OnSettingButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("Setting button clicked"));
}

void UUI_StartMenuBase::OnExitButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("Exit button clicked"));
	auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
	auto PlayerController = GetOwningPlayer();
	GameMode->ShowGameLoginUI(PlayerController);
	RemoveFromParent();
}