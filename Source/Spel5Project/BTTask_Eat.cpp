// Diego Puentes Varas dipu6255

#include "BTTask_Eat.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Eat::UBTTask_Eat()
{
	NodeName = TEXT("Eat");
}

EBTNodeResult::Type UBTTask_Eat::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	DogCharacter->SetIsDoorOpen(true);
	return EBTNodeResult::Succeeded;
}
