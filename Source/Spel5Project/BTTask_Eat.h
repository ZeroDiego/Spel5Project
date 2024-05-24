// Diego Puentes Varas dipu6255

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Eat.generated.h"

/**
 * 
 */
UCLASS()
class SPEL5PROJECT_API UBTTask_Eat : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_Eat();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
