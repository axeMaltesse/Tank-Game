// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	UE_LOG(LogTemp,Warning,TEXT("chujoza"))
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>(); // Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
	//TODO Fire if ready
	//ControlledTank->Fire();//TODO fix firing
}



