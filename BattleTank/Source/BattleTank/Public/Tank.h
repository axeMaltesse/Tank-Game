// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Always last

// Forward declarations
class UTankAimingComponent;
class UTankMovementComponent;
class UTankBarrel; 
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();	
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; //sesible starting value 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr; //Local barrel Reference for spawning projectile

	float ReloadTimeInseconds = 3;

	double LastFireTime = 0;
};
