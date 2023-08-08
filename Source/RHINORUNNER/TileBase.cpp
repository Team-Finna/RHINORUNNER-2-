// Fill out your copyright notice in the Description page of Project Settings.


#include "TileBase.h"

// Sets default values
ATileBase::ATileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATileBase::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation(); 
}

// Called every frame
void ATileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	IsTileOutOfVisualizedArea();
	MoveToStartLocation();


}

bool ATileBase::IsTileOutOfVisualizedArea()
{
	if (NearBounds && FarBounds)
	{
		
		
		if (GetActorLocation().X < NearBounds->GetActorLocation().X)
		{
			UE_LOG(LogTemp, Warning, TEXT("Out of bounds near"));
			return true;
		}

		else if (GetActorLocation().X > FarBounds->GetActorLocation().X)
		{
			UE_LOG(LogTemp, Warning, TEXT("Out of bounds far") );
			return true;
		}
		else return false;

		
	}
	else return false;


}

FVector ATileBase::MoveToStartLocation()
{
	FVector Start = StartLocation; 

	if ( NearBounds && GetActorLocation().X < NearBounds->GetActorLocation().X)
	{
		SetActorLocation(StartLocation);
	}

	return Start;
}

