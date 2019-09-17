// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		FString temp = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController BeginPlay in: %s"), *(temp));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank"));
	}

	if (GetPlayerTank())
	{
		FVector position = GetPlayerTank()->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Found the player Tank at: %s"), *(position.ToString()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find player tank"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
