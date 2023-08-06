// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingTileBase.generated.h"

UENUM()
enum class TileType
{
	NONE,
	Building,
	Road,

};

USTRUCT()
struct FTiles
{
	GENERATED_BODY()

	int32 Row;
	int32 Column;
	float size;
	FVector Location;
	UStaticMeshComponent* Mesh;
};

UCLASS()
class RHINORUNNER_API AMovingTileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingTileBase();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TileMesh;
	TArray<UStaticMeshComponent*> TileMeshes;

	TArray<FTiles> Tiles; 

	UPROPERTY(EditAnywhere)
		int32 GridSizeX = 5;
	UPROPERTY(EditAnywhere)
		int32 GridSizeY = 5;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	UFUNCTION()
	void DrawTile(float xSize, float ySize, FTiles& t);

};
