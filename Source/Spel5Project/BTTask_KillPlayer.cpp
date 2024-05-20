// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_KillPlayer.h"
#include "AIController.h"
#include "OwnerCharacter.h"

UBTTask_KillPlayer::UBTTask_KillPlayer()
{
	NodeName = TEXT("KillPlayer");
}

EBTNodeResult::Type UBTTask_KillPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AOwnerCharacter* OwnerCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerCharacter == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	//OwnerCharacter->KillPlayer();
	
	return EBTNodeResult::Succeeded;
}