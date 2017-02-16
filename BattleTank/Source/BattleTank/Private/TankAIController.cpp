// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		//Move forwards to player direction
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius
		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//TODO Fire if ready
		ControlledTank->Fire();//TODO limit firing rate
	}
}


