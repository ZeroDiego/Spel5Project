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

	virtual void Tick(float DeltaTime) override;

	// Properties
	UPROPERTY(EditAnywhere, Category = "Environment")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Environment")
	UPhysicsConstraintComponent* PhysicsComponent;

	UPROPERTY(EditAnywhere, Category = "Environment")
	UPhysicsHandleComponent* PhysicsHandleComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Overlap")
	bool bOwnerOverlapping;

	UPROPERTY(BlueprintReadWrite, Category = "Overlap")
	bool bCharOverlapping;

	// Function to enable physics simulation
	UFUNCTION(BlueprintCallable, Category = "Physics")
	void EnablePhysics();

	// Function to disable physics simulation
	UFUNCTION(BlueprintCallable, Category = "Physics")
	void DisablePhysics();
};