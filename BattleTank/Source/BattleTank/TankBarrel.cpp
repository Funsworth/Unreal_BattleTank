// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move the barrel the right amount this frame
	//Give a max elevation speed
	UE_LOG(LogTemp, Warning, TEXT("Elevate: %f"), DegreesPerSecond);
}