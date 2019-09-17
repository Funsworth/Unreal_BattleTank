// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	
	if (GetControlledTank())
	{
		FString temp = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController BeginPlay in: %s"), *(temp));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAITankPlayerControllerController not possesing a tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	//UE_LOG(LogTemp, Warning, TEXT("PC Tick"));
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
		return;

	FVector HitLocation = FVector::ZeroVector; //OUT parameter
	UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *(HitLocation.ToString()));
	GetSightRayHitLocation(HitLocation);
	UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *(HitLocation.ToString()));

	//get world location linetracing through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &Out) const
{
	Out.X = 5.0f;
	

	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

