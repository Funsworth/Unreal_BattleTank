// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Turret Rotate"));
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	//auto Rotation = FMath::Clamp<float>(RawNewRotation, MinRotation, MaxRotation);
	SetRelativeRotation(FRotator(0, Rotation, 0));
}
