// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"



UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Drive the tracks
	DriveTrack();
	ApplySidewaysForce();

	CurrentThrottle = 0;
}

void UTankTrack::ApplySidewaysForce()
{
	//calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	//work-out the required acceleration this fram to correct
	
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectingAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calculate and apply the force F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectingAcceleration / 2; //Two Tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


