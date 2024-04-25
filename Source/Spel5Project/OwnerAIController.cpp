// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AOwnerAIController::BeginPlay()
{
	Super::BeginPlay();

	PawnSensingComponent = FindComponentByClass<UPawnSensingComponent>();
	if (PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AOwnerAIController::OnSeePlayer);
	}

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

void AOwnerAIController::SetAlerted() const
{
	AOwnerCharacter* ControlledCharacter = Cast<AOwnerCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
	{
		ControlledCharacter->SetIsAlerted(true);
	}
}

float AOwnerAIController::GetVisionRange() const
{
	return VisionRange;
}

void AOwnerAIController::OnSeePlayer(APawn* SeenPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	
	if (SeenPawn && SeenPawn == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
		if (BlackboardComp)
		{
			BlackboardComp->SetValueAsObject("Player", SeenPawn);
			UE_LOG(LogTemp, Warning, TEXT("Hello"));
		}
	}
}