// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileBase.generated.h"

UENUM(BlueprintType)
enum class TileType
{
	NONE,
	Architecture, 
	Transition,
	ObsticleSpawn
};
UCLASS()
class RHINORUNNER_API ATileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	UStaticMeshComponent* Mesh; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor> ActorToSpawn; 
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformRefreshEvent(TSubclassOf<ATileBase> Previous);


	UPROPERTY(BlueprintReadWrite)
	TileType Current; 

	UPROPERTY(BlueprintReadWrite)
		bool CanSpawn;

	UPROPERTY(BlueprintReadWrite)
		int Column;

	UPROPERTY(BlueprintReadWrite)
		int Row; 
	



	 


};
