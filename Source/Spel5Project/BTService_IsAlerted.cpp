// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_IsAlerted.h"
#include "OwnerCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_IsAlerted::UBTService_IsAlerted()
{
	NodeName = TEXT("Update Is Alerted");
}

void UBTService_IsAlerted::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AOwnerCharacter* ControlledCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (ControlledCharacter == nullptr)
	{
		return;
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsAlerted"), ControlledCharacter->GetIsAlerted());
}