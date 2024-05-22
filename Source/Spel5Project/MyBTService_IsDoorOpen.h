// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_IsDoorOpen.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UMyUBTService_IsDoorOpen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyUBTService_IsDoorOpen();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};