// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto controlledAITank = GetAIControlledTank();
	if (!controlledAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI possesed tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possesed tank: %s"), *(controlledAITank -> GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cant see player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("See player controller: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		
		FVector HitLocation = GetPlayerTank()->GetTargetLocation();
		if (GetAIControlledTank())
		{
			//TODO move towards Player
			GetAIControlledTank()->AimAt(HitLocation);
			//fire if ready
		}
	}
}


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
	
}