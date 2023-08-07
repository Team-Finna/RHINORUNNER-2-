// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AObstacleBase::AObstacleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(Root);
	CollisionBox->SetBoxExtent(FVector(50.f, 250.f, 50.f));
}

// Called when the game starts or when spawned
void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

