// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//moves the tank barrel so that it is aiming at crosshair
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector &Out) const;


private:

};
