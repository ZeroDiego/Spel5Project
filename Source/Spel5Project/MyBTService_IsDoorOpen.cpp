// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTService_IsDoorOpen.h"
#include "DogCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyUBTService_IsDoorOpen::UMyUBTService_IsDoorOpen()
{
	NodeName = TEXT("Update Is Door Open");
}

void UMyUBTService_IsDoorOpen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(TEXT("IsDoorOpen"), ControlledCharacter->GetIsSleeping());
}