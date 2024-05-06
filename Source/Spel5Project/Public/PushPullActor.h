#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "PushPullActor.generated.h"

class UPhysicsConstraintComponent;
class UPhysicsHandleComponent;

UCLASS()
class SPEL5PROJECT_API APushPullActor : public AActor
{
	GENERATED_BODY()
    
public:
	APushPullActor();
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	UPROPERTY(EditAnywhere, Category="Environment")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category="Environment")
	UPhysicsConstraintComponent* PhysicsComponent;

	UPROPERTY(EditAnywhere, Category="Environment")
	UPhysicsHandleComponent* PhysicsHandleComponent;
	

	void PullObject(const FVector& PlayerLocation);
	void ReleaseObject();

	UPROPERTY(EditAnywhere, Category = "Player")
	TSubclassOf<AActor> PlayerBlueprintClass;

protected:
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsGrabbed = false;
	FVector GrabLocation;
};