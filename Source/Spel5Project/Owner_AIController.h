// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Owner_AIController.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API AOwner_AIController : public AAIController
{

private:
	GENERATED_BODY()

public:
	explicit AOwner_AIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;
	
};
