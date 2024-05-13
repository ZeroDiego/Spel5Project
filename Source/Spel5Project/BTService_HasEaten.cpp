// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_HasEaten.h"
#include "DogCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_HasEaten::UBTService_HasEaten()
{
	NodeName = TEXT("Update Has Eaten");
}

void UBTService_HasEaten::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("HasEaten"), ControlledCharacter->GetHasEaten());
}