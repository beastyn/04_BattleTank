// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	
	virtual void BeginPlay() override;

public:	
	// Sets default values for this pawn's properties
	ATank();
		

	

};
