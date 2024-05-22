// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_HasEaten.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UBTService_HasEaten : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_HasEaten();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
