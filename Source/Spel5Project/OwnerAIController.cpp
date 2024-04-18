// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AOwnerAIController::BeginPlay()
{
	Super::BeginPlay();

	if(AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AOwnerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOwnerAIController::SetAlerted(bool NewIsAlerted) const
{

}

float AOwnerAIController::GetVisionRange() const
{
	return VisionRange;
}
