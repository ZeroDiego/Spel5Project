// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CloseDogWall.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CloseDogWall::UBTTask_CloseDogWall()
{
	NodeName = TEXT("Close Wall");
}

EBTNodeResult::Type UBTTask_CloseDogWall::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	ADogCharacter* DogCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (DogCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UMover* Mover = DogCharacter->GetMover();
	if (Mover == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Mover->SetShouldMove(false);
	return EBTNodeResult::Succeeded;
}