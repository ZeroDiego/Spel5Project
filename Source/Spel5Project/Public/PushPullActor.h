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

	virtual void Tick(float DeltaTime) override;

	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Environment")
	UPhysicsConstraintComponent* PhysicsComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Environment")
	UPhysicsHandleComponent* PhysicsHandleComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Overlap")
	bool bOwnerOverlapping;

	UPROPERTY(BlueprintReadWrite, Category = "Overlap")
	bool bCharOverlapping;

	UPROPERTY(BlueprintReadWrite, Category = "Pull")
	bool bPullEnabled;

	UPROPERTY(BlueprintReadWrite, Category = "Pull")
	float ForceMagnitude;

	// Function to enable physics simulation
	UFUNCTION(BlueprintCallable, Category = "Physics")
	void EnablePhysics();

	// Function to disable physics simulation
	UFUNCTION(BlueprintCallable, Category = "Physics")
	void DisablePhysics();

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void PushBackwards();
};