// Diego Puentes Varas dipu6255


#include "BTTask_ClearBlackboardValue.h"
#include "AIController.h"
#include "DogCharacter.h"
#include "OwnerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue::UBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("Clear Board Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	if(ADogCharacter* DogCharacter = Cast<ADogCharacter>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if (GetSelectedBlackboardKey() == "IsBarking")
			DogCharacter->SetIsBarking(false);
		else if (GetSelectedBlackboardKey() == "IsSatisfied")
			DogCharacter->SetIsSatisfied(false);
		else if (GetSelectedBlackboardKey() == "IsEating")
			DogCharacter->SetIsEating(false);
	}

	if (AOwnerCharacter* OwnerCharacter = Cast<AOwnerCharacter>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if (GetSelectedBlackboardKey() == "LastKnownPlayerLocation")
			OwnerCharacter->SetLastKnownPlayerLocation(FVector::ZeroVector);
		else if (GetSelectedBlackboardKey() == "IsAlerted")
			OwnerCharacter->SetIsAlerted(false);
	}
	
	return EBTNodeResult::Succeeded;
}

