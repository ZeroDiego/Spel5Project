// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Sleep.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UBTTask_Sleep : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_Sleep();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
