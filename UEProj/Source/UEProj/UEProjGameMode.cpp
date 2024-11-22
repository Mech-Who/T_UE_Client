// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEProjGameMode.h"
#include "UEProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUEProjGameMode::AUEProjGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
