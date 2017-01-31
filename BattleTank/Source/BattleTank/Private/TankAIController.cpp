// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI can find the player %s"), *(PlayerTank->GetName()))
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Null pointer at GetPlayerTank method inside TankAIController.cpp"))
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
