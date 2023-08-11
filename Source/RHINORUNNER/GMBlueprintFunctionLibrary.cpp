// Fill out your copyright notice in the Description page of Project Settings.


#include "GMBlueprintFunctionLibrary.h"

FVector UGMBlueprintFunctionLibrary::RandomLocation(FVector InputVector, float Variation)
{
	FVector ReturnVector = InputVector + FVector(FMath::RandRange(-1 * Variation, Variation), FMath::RandRange(-1 * Variation, Variation), InputVector.Z);
	return ReturnVector;
}
