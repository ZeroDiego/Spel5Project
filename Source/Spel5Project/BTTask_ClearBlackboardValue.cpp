// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboardValue.h"
#include "AIController.h"
#include "OwnerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("Clear Board Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	AOwnerCharacter* ControlledCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (ControlledCharacter)
	{
		if (GetSelectedBlackboardKey() == "LastKnownPlayerLocation")
		{
			ControlledCharacter->SetLastKnownPlayerLocation(FVector::ZeroVector);
		}
		else if (GetSelectedBlackboardKey() == "IsAlerted")
		{
			ControlledCharacter->SetIsAlerted(false);
		}
	}
	
	return EBTNodeResult::Succeeded;
}

