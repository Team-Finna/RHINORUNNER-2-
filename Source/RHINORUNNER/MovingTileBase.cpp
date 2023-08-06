// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingTileBase.h"

// Sets default values
AMovingTileBase::AMovingTileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	
}

// Called when the game starts or when spawned
void AMovingTileBase::BeginPlay()
{
	Super::BeginPlay();

	TileMeshes.SetNum(GridSizeX * GridSizeY);
	

	Tiles.SetNum(GridSizeX * GridSizeY);

	for (int j = 0; j < Tiles.Num(); j++)
	{
		
		for (int i = 0; i < GridSizeX; i++)
		{
			for (int ii = 0; ii < GridSizeY; ii++)
			{
			
				Tiles[j].Column = ii; 
				Tiles[j].Row = i;
				Tiles[j].Mesh = TileMeshes[j];
			}
		}
	}

	for (int i = 0; i < Tiles.Num(); i++)
	{
		DrawTile(12, 12, Tiles[1]);
		UE_LOG(LogTemp, Warning, TEXT("Grid x : % i, and Grid y : % i"), Tiles[i].Row, Tiles[i].Column);
	}
	
	
	
}

// Called every frame
void AMovingTileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovingTileBase::DrawTile(float xSize, float ySize, FTiles& t)
{
	//draw tile to the screen; 
	float TileRow = t.Row;
	float TileColumn = t.Column;
	
	FVector location = FVector(xSize * TileRow, ySize * TileColumn, t.Mesh->GetRelativeLocation().Z * 0.5f);
	
	t.Mesh->SetWorldLocation(location);
	

}

