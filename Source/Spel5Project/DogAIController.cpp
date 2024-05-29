// Diego Puentes Varas dipu6255

#include "DogAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void ADogAIController::BeginPlay()
{
	Super::BeginPlay();

	if(AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		const ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(GetPawn());
		GetBlackboardComponent()->SetValueAsBool(TEXT("IsSatisfied"), ControlledCharacter->GetIsSatisfied());
	}
}

void ADogAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADogAIController::SetSatisfied() const
{
	if (ADogCharacter* ControlledCharacter = Cast<ADogCharacter>(GetPawn()); ControlledCharacter != nullptr)
		ControlledCharacter->SetIsSatisfied(true);
}

float ADogAIController::GetVisionRange() const
{
	return VisionRange;
}
