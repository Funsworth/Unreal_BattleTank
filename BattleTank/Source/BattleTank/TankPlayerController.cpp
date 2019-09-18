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
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	//get world location linetracing through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);	

	//Find the world direction of the crosshair
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace along that line
		GetLookVectorHitLocation(LookDirection, HitLocation);		
	}
	return true;
}

//Takes in LookDirection and changes it to via DeprojectScreenPositionToWorld
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection));	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LookDirection * LineTraceRange);	

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECollisionChannel::ECC_Visibility))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Result: %s"), *(HitResult.Location.ToString()));
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

