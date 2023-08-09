// Fill out your copyright notice in the Description page of Project Settings.


#include "TileBase.h"

// Sets default values
ATileBase::ATileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	ActorToSpawn = AActor::StaticClass(); 
	
}

// Called when the game starts or when spawned
void ATileBase::BeginPlay()
{
	Super::BeginPlay();
	if (Column == 0 || Column == 1 || Column == 7 || Column == 8)
	{
		Current = TileType::Architecture;
		
		
	}
}

// Called every frame
void ATileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	//MoveToStartLocation();
}

void ATileBase::PerformRefreshEvent_Implementation(TSubclassOf<ATileBase> Previous)
{
	if (Column == 0 || Column == 1 || Column == 8 || Column == 7)
	{
		CanSpawn = true; 
	}
	
}




