// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_IsEating.h"
#include "DogCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_IsEating::UBTService_IsEating()
{
	NodeName = TEXT("Update IsEating");
}

void UBTService_IsEating::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsEating"), ControlledCharacter->GetIsEating());
}