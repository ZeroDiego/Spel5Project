// Fill out your copyright notice in the Description page of Project Settings.


#include "Owner_AIController.h"

#include "AI_Owner.h"

AOwner_AIController::AOwner_AIController(FObjectInitializer const& ObjectInitializer)
{
	
}

void AOwner_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AAI_Owner* const AI_Owner = Cast<AAI_Owner>(InPawn))
		
	{
		if (UBehaviorTree* const Tree = AI_Owner->GetBehaviorTree())
		{


			UBlackboardComponent* b;
			UseBlackboard(Tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(Tree);
			
			
		}
	}
}
