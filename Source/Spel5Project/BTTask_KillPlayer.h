// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_KillPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UBTTask_KillPlayer : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_KillPlayer();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
