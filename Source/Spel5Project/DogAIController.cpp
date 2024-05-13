// Fill out your copyright notice in the Description page of Project Settings.


#include "DogAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void ADogAIController::BeginPlay()
{
	Super::BeginPlay();

	if(AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(GetPawn());
		GetBlackboardComponent()->SetValueAsBool(TEXT("IsSatisfied"), ControlledCharacter->GetIsSatisfied());
	}
}

void ADogAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADogAIController::SetSatisfied() const
{
	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		ControlledCharacter->SetSatisfied(true);
	}
}

float ADogAIController::GetVisionRange() const
{
	return VisionRange;
}
