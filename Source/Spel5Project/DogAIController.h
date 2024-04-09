// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DogAIController.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API ADogAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    void Tick(float DeltaTime) override;
	bool IsEating() const;

protected:
	void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};
