// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mover.h"
#include "GameFramework/Character.h"
#include "DogCharacter.generated.h"

UCLASS()
class SPEL5PROJECT_API ADogCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADogCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	bool GetIsSatisfied() const;
	
	void SetSatisfied(bool NewIsSatisfied);
	
	void Sleep();

	void Alert();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UMover* GetMover() const;
	
	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* NewMover);
	
private:
	UPROPERTY(VisibleAnywhere)
	bool IsSatisfied;

	UPROPERTY(VisibleAnywhere)
	bool IsSleeping;

	UPROPERTY(VisibleAnywhere)
	bool IsAlert;
	
	UPROPERTY(EditAnywhere)
	float SleepDelay = 1;
	
	UPROPERTY(EditAnywhere)
	USoundBase* BarkSound;

	UPROPERTY(EditAnywhere)
	USoundBase* EatSound;
	
	FTimerHandle SleepTimer;

	UMover* Mover;
};