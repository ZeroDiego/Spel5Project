// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DogCharacter.h"
#include "DogComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPEL5PROJECT_API UDogComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDogComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetDog(ADogCharacter* NewDogCharacter);

	UFUNCTION(BlueprintCallable)
	bool GetDogIsSatisfied() const;

	UFUNCTION(BlueprintCallable)
	void SetDogIsSatisfied(const bool NewIsSatisfied) const;

	UFUNCTION(BlueprintCallable)
	bool GetDogIsSleeping() const;

	UFUNCTION(BlueprintCallable)
	void SetDogIsSleeping(const bool NewIsSleeping) const;
	
private:
	ADogCharacter* DogCharacter;
	
};
