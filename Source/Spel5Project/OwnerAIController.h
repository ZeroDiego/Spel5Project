// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "OwnerCharacter.h"
#include "Perception/PawnSensingComponent.h"
#include "OwnerAIController.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API AOwnerAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void Tick(float DeltaTime) override;
	void SetAlerted() const;

	float GetVisionRange() const;

protected:
	void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;

	UPROPERTY(EditAnywhere)
	float VisionRange;

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensingComponent;

	UFUNCTION()
	void OnSeePlayer(APawn* SeenPawn);
};
