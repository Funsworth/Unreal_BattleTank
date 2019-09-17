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
	//UE_LOG(LogTemp, Warning, TEXT("PC Tick"));
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
		return;

	//get world location linetracing through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

