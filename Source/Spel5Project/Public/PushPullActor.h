#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PushPullActor.generated.h"

class UPhysicsConstraintComponent;
class UPhysicsHandleComponent;

UCLASS()
class SPEL5PROJECT_API APushPullActor : public AActor
{
	GENERATED_BODY()
    
public:
	APushPullActor();

	UPROPERTY(EditAnywhere, Category="Environment")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category="Environment")
	UPhysicsConstraintComponent* PhysicsComponent;

	UPROPERTY(EditAnywhere, Category="Environment")
	UPhysicsHandleComponent* PhysicsHandleComponent;

	void PullObject(const FVector& PlayerLocation);
	void ReleaseObject();

protected:
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsGrabbed = false;
	FVector GrabLocation;
};