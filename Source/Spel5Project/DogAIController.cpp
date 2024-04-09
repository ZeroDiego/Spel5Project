// Fill out your copyright notice in the Description page of Project Settings.


#include "DogAIController.h"
#include "DogCharacter.h"
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
		
	}
}

void ADogAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ADogAIController::IsEating() const
{
	ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsEating();
	}
	return true;
}