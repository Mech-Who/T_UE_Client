// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"

#include "ABP_Cube.h"
#include "UEProjProjectile.h"
#include "GameSetting/UEProjGameMode.h"

// Sets default values
AABP_Cube::AABP_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 创建静态网格组件
	StaticCubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = StaticCubeMesh;
	// 加载默认方块模型
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeAsset.Succeeded()) {
		StaticCubeMesh->SetStaticMesh(CubeAsset.Object);
	}
    // Register Hit Event
	if (StaticCubeMesh)
		StaticCubeMesh -> OnComponentHit.AddDynamic(this, &AABP_Cube::OnHit);
}

// Called when the game starts or when spawned
void AABP_Cube::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AABP_Cube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AABP_Cube::SetMaterial(UMaterialInterface* NewMaterial)
{
	if (NewMaterial && this->StaticCubeMesh) {
		StaticCubeMesh->SetMaterial(0, NewMaterial);
	}
}

void AABP_Cube::BeImportant(int NewScore, UMaterialInterface* NewMaterial)
{
	this->IsImportant = true;
	this->ScoreValue = NewScore;
	this->SetMaterial(NewMaterial);
}

// Process when hitted
void AABP_Cube::OnHit(
	UPrimitiveComponent* HitComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
		if (OtherActor && OtherActor->IsA(AUEProjProjectile::StaticClass())) {
			ScaleFactor -= 0.5f;  // scale to 50% each time
			// Notify GameMode to add score
			UE_LOG(LogTemp, Log, TEXT("Hit Actor"));
			if (AUEProjGameMode* GameMode = Cast<AUEProjGameMode>(UGameplayStatics::GetGameMode(GetWorld()))) {
				GameMode->UpdateScore(ScoreValue);
				UE_LOG(LogTemp, Log, TEXT("Update Score: %d + (%d)"), GameMode->TotalScore, ScoreValue);
			}
			if (ScaleFactor <= MinScale) {
				Destroy();  // destroy cube
			} else {
				SetActorScale3D(FVector(ScaleFactor));
			}
		}
}

