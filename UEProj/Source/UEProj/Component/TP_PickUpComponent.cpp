// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_PickUpComponent.h"

#include "Kismet/GameplayStatics.h"

#include "UEProj/GameSetting/UEProjGameMode.h"
#include "UEProj/UEProjCharacter.h"

UTP_PickUpComponent::UTP_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTP_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTP_PickUpComponent::OnSphereBeginOverlap);
}

void UTP_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AUEProjCharacter* Character = Cast<AUEProjCharacter>(OtherActor);
	if(Character != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Character is valid!"));
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);
		
		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);

		if (AUEProjGameMode* GameMode = Cast<AUEProjGameMode>(UGameplayStatics::GetGameMode(GetWorld()))) {
			GameMode->StartGame();
			UE_LOG(LogTemp, Display, TEXT("===== Game Start ====="));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Character is invalid!"));
	}
}
