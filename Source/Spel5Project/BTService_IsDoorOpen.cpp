// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_IsDoorOpen.h"
#include "DogCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_IsDoorOpen::UBTService_IsDoorOpen()
{
	NodeName = TEXT("Update Is Door Open");
}

void UBTService_IsDoorOpen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsDoorOpen"), ControlledCharacter->GetIsDoorOpen());
}