// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_DogOwnerPlayerLocation.h"
#include "OwnerCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_DogOwnerPlayerLocation::UBTService_DogOwnerPlayerLocation()
{
	NodeName = TEXT("Update LastKnownPlayerLocaton");
}

void UBTService_DogOwnerPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AOwnerCharacter* ControlledCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), ControlledCharacter->GetLastKnownPlayerLocation());
}