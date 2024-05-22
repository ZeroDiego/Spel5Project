// Diego Puentes Varas dipu6255

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OwnerCharacter.generated.h"

UCLASS()
class SPEL5PROJECT_API AOwnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOwnerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	bool GetIsAlerted() const;

	UFUNCTION(BlueprintCallable)
	void SetIsAlerted(bool NewIsAlerted);

	UFUNCTION(BlueprintCallable)
	FVector GetLastKnownPlayerLocation() const;

	UFUNCTION(BlueprintCallable)
	void SetLastKnownPlayerLocation(const FVector& NewLastKnownPlayerLocation);

	//void KillPlayer() const;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	bool IsAlerted;

	UPROPERTY(VisibleAnywhere)
	FVector LastKnownPlayerLocation;
};
