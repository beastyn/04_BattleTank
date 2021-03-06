// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Classes/Engine/World.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


protected:
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 8000;

private:

	virtual void SetPawn(APawn* InPawn) override;
	
	UFUNCTION()
	void OnTankDeath();
	
	APawn* PossesedTank;
	
};
