// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"
#include "Engine/World.h"
// #include "TimerManager.h"

#include "UI_LoginBase.h"
#include "UEProj/GameSetting/UEProjGameMode.h"

void UUI_LoginBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ErrorHintText->SetOpacity(0.0);
	ConfirmButton->OnClicked.AddDynamic(this, &UUI_LoginBase::OnConfirmButtonClicked);
	CancelButton->OnClicked.AddDynamic(this, &UUI_LoginBase::OnCancelButtonClicked);
}

bool UUI_LoginBase::Login(FString Username, FString Password)
{
	if (Username == "" || Password == "")
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Username or Password"));
		return false;
	}
	if (Username == "admin" && Password == "123456")
	{
		UE_LOG(LogTemp, Error, TEXT("Admin Login!"));
		return true;
	}
	UE_LOG(LogTemp, Display, TEXT("Current UserName: %s, Password: %s"), *Username, *Password);
	return true;
}

FString UUI_LoginBase::GetPassword()
{
	return PasswordEditText->GetText().ToString();
}

FString UUI_LoginBase::GetUsername()
{
	return UsernameEditText->GetText().ToString();
}

void UUI_LoginBase::OnConfirmButtonClicked()
{
	ErrorHintText->SetOpacity(0.0);
	if (Login())
	{
		auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
		if (auto PlayerController = GetOwningPlayer())
		{
			GameMode->ShowGameStartUI(PlayerController);
		}
		RemoveFromParent();
	}
	else
	{
		ErrorHintText->SetOpacity(1.0);
	}
}

void UUI_LoginBase::OnCancelButtonClicked()
{
	auto GameMode = Cast<AUEProjGameMode>(GetWorld()->GetAuthGameMode());
	GameMode->QuitGame();
}

bool UUI_LoginBase::Login()
{
	return Login(GetUsername(), GetPassword());
}
