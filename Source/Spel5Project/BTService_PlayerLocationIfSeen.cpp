// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "AIController.h"
#include "DogAIController.h"
#include "OwnerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update player location if seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn == nullptr)
	{
		return;
	}

	ADogAIController* DogAIController = Cast<ADogAIController>(OwnerComp.GetOwner());
	AOwnerCharacter* OwnerCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	const float DistanceToPlayer = FVector::Distance(PlayerPawn->GetActorLocation(), OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation());

	if (OwnerCharacter != nullptr && OwnerCharacter->GetIsAlerted())
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
		return;
	}

	if (DogAIController != nullptr)
	{
		if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn) && DistanceToPlayer <= DogAIController->GetVisionRange())
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
		}
		else
		{
			OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		}
	}
}
