// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OwnerCharacter.generated.h"

UCLASS()
class SPEL5PROJECT_API AOwnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOwnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	bool GetIsAlerted() const;

	UFUNCTION(BlueprintCallable)
	void SetIsAlerted(bool NewIsAlerted);

	UFUNCTION(BlueprintCallable)
	FVector GetLastKnownPlayerLocation() const;

	UFUNCTION(BlueprintCallable)
	void SetLastKnownPlayerLocation(const FVector& NewLastKnownPlayerLocation);

	void KillPlayer() const;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	bool IsAlerted;

	UPROPERTY(VisibleAnywhere)
	FVector LastKnownPlayerLocation;
};
