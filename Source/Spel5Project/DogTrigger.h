// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "DogCharacter.h"
#include "DogTrigger.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPEL5PROJECT_API UDogTrigger : public UCapsuleComponent
{
	GENERATED_BODY()

public:
	UDogTrigger();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetDog(ADogCharacter* NewDogCharacter);
	
private:
	UPROPERTY(EditAnywhere)
	FName MeatTag;

	ADogCharacter* DogCharacter;
	
	AActor* GetMeatActor() const;
	
};
