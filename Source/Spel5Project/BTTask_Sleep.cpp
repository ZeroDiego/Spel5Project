// Diego Puentes Varas dipu6255

#include "BTTask_Sleep.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Sleep::UBTTask_Sleep()
{
	NodeName = TEXT("Sleep");
}

EBTNodeResult::Type UBTTask_Sleep::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	DogCharacter->SetIsSleeping(true);
	return EBTNodeResult::Succeeded;
}