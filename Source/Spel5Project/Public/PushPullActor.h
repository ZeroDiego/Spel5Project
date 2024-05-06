#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "PushPullActor.generated.h"

class UPhysicsConstraintComponent;
class UPhysicsHandleComponent;
class UInputComponent;

UCLASS()
class SPEL5PROJECT_API APushPullActor : public AActor
{
	GENERATED_BODY()

public:
	APushPullActor();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// Updated method signatures to match the new input handling approach
	void OnPullObjectPressed();
	void OnReleaseObjectReleased();

	// Existing methods
	void PullObject();
	void ReleaseObject();

	// Method to set the player blueprint class from the blueprint editor
	void SetPlayerBlueprintClass(TSubclassOf<ACharacter> NewPlayerBlueprintClass);

	// Properties
	UPROPERTY(EditAnywhere, Category = "Environment")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Environment")
	UPhysicsConstraintComponent* PhysicsComponent;

	UPROPERTY(EditAnywhere, Category = "Environment")
	UPhysicsHandleComponent* PhysicsHandleComponent;

protected:
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsGrabbed = false;
	FVector GrabLocation;
	TSubclassOf<AActor> PlayerBlueprintClass;
};