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

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

