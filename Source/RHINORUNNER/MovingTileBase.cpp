// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingTileBase.h"

// Sets default values
AMovingTileBase::AMovingTileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingTileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingTileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

