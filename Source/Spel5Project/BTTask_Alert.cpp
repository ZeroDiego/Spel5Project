// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Alert.h"
#include "AIController.h"
#include "DogCharacter.h"

UBTTask_Alert::UBTTask_Alert()
{
	NodeName = TEXT("Alert");
}

EBTNodeResult::Type UBTTask_Alert::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	ADogCharacter* Character = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("EBTNodeResult::Failed"));
		return EBTNodeResult::Failed;
	}

	Character->Alert();

	UE_LOG(LogTemp, Display, TEXT("EBTNodeResult::Succeeded"));
	return EBTNodeResult::Succeeded;
}
