// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Classes/Engine/World.h"

void UTankTurret::TurretRotation(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSec*GetWorld()->DeltaTimeSeconds;
	auto NewTurretRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewTurretRotation, 0));
}
