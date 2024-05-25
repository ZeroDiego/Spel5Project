// Diego Puentes Varas dipu6255

#include "BTTask_Alert.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "OwnerCharacter.h"
#include "Engine.h"
#include "Logging/LogMacros.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Alert::UBTTask_Alert()
{
	NodeName = TEXT("Alert");
}

EBTNodeResult::Type UBTTask_Alert::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	DogCharacter->Alert();
	DogCharacter->SetIsBarking(true);

	const UWorld* World = GetWorld();
	for (TActorIterator<AOwnerCharacter> It(World); It; ++It)
	{
		if (AOwnerCharacter* FoundOwner = *It)
		{
			FoundOwner->SetIsAlerted(true);
			FoundOwner->SetLastKnownPlayerLocation(OwnerComp.GetBlackboardComponent()->GetValueAsVector("LastKnownPlayerLocation"));
			break;
		}
	}
	
	return EBTNodeResult::Succeeded;
}