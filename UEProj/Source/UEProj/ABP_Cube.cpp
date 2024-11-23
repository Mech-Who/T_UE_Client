// Fill out your copyright notice in the Description page of Project Settings.


#include "ABP_Cube.h"
#include "UEProjProjectile.h"
#include "UEProjGameMode.h"
#include "Kismet/GameplayStatics.h"

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

// Process when hitted
void AABP_Cube::OnHit(
	UPrimitiveComponent* HitComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
		if (OtherActor && OtherActor->IsA(AUEProjProjectile::StaticClass())) {
			ScaleFactor -= 0.5f;  // scale to 50% each time
			if (ScaleFactor <= MinScale) {
				// Notify GameMode to add score
				if (AUEProjGameMode* GameMode = Cast<AUEProjGameMode>(UGameplayStatics::GetGameMode(GetWorld()))) {
					GameMode->AddScore(ScoreValue);
				}
				Destroy();  // destroy cube
			} else {
				SetActorScale3D(FVector(ScaleFactor));
			}
		}
}

