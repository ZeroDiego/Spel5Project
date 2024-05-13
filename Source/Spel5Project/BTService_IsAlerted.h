// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_IsAlerted.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UBTService_IsAlerted : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_IsAlerted();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
