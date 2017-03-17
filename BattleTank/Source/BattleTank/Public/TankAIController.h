// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h" //always include last

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void Tick(float DeltaTime) override;

	//How close can AI tank be next to player
	float AcceptanceRadius = 3000;
};
