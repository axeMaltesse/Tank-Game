// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("Null pointer at GetPlayerTank method inside TankAIController.cpp"))
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTankLoation = GetPlayerTank()->GetActorLocation();
	if (GetPlayerTank()) {
		//TODO Move forwards to player direction

		//Aim towards the player
		GetTankAIController()->AimAt(PlayerTankLoation);

		//TODO Fire if ready
	}
}

ATank * ATankAIController::GetTankAIController() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerTank) {return Cast<ATank>(PlayerTank);}
	else {return nullptr;}
}
