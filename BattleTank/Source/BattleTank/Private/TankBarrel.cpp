// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Classes/Engine/World.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSec*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	// Take rptation for aim direction
	//change angle for barrel
	auto ClampedElevation =FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
	
	
}


