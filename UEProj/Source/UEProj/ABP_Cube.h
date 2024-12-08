// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ABP_Cube.generated.h"

UCLASS()
class UEPROJ_API AABP_Cube : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AABP_Cube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetMaterial(UMaterialInterface* NewMaterial);
	void BeImportant(int NewScore, UMaterialInterface* NewMaterial=nullptr);
	
	// process when hit
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	bool IsImportant=false;
	// Current score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	int ScoreValue=5;
	// Current scale factor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	double ScaleFactor=1.0f;
	// minimal scale value, destroy this actor when ScaleFactor < MinScale
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	double MinScale=0.3f;
	// Cube mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube")
	UStaticMeshComponent* StaticCubeMesh;
};
