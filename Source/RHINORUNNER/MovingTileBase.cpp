// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingTileBase.h"
#include "Components/StaticMeshComponent.h"

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

	
	TileComponents.SetNum(GridSizeX * GridSizeY);
	Tiles.SetNum(TileComponents.Num());
	
	
	for (int i = 0; i < TileComponents.Num(); i++)
	{
		TileComponents[i].Tile = Tiles[i].GetDefaultObject();
		
	}

	
		
		for (int i = 0; i < GridSizeX; i++)
		{
			for (int ii = 0; ii < GridSizeY; ii++)
			{
				TileComponents[i].Row = i; 
				TileComponents[ii].Column = ii; 
				
		
			
			}
		}

	
		DrawTile(TileComponents[3]);
	
	
	
}



// Called every frame
void AMovingTileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovingTileBase::DrawTile(FTiles& t)
{
	//draw tile to the screen; 
	float TileRow = t.Row;
	float TileColumn = t.Column;
	
	FVector location = FVector(t.size * TileRow, t.size * TileColumn, 0);
	
	t.Tile->SetActorLocation(location);
	t.Tile->SetActorHiddenInGame(false);
	
	

}

