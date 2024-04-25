// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_IsSatisfied.h"
#include "DogCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_IsSatisfied::UBTService_IsSatisfied()
{
	NodeName = TEXT("Update Is Satisfied");
}

void UBTService_IsSatisfied::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsSatisfied"), ControlledCharacter->GetIsSatisfied());
}