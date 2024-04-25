// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Alert.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "OwnerCharacter.h"
#include "Engine.h"

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

	ADogCharacter* DogCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (DogCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	DogCharacter->Alert();

	const UWorld* World = GetWorld();
	for (TActorIterator<AOwnerCharacter> It(World); It; ++It)
	{
		if (AOwnerCharacter* FoundOwner = *It)
		{
			FoundOwner->SetIsAlerted(true);
			break;
		}
	}

	return EBTNodeResult::Succeeded;
}
