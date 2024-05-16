// Fill out your copyright notice in the Description page of Project Settings.


#include "DogComponent.h"

// Sets default values for this component's properties
UDogComponent::UDogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UDogComponent::SetDog(ADogCharacter* NewDogCharacter)
{
	DogCharacter = NewDogCharacter;
}

bool UDogComponent::GetDogIsSatisfied() const
{
	return DogCharacter->GetIsSatisfied();
}

void UDogComponent::SetDogIsSatisfied(const bool NewIsSatisfied) const
{
	DogCharacter->SetSatisfied(NewIsSatisfied);
}

bool UDogComponent::GetDogIsSleeping() const
{
	return DogCharacter->GetIsSleeping();
}

void UDogComponent::SetDogIsSleeping(const bool NewIsSleeping) const
{
	DogCharacter->SetIsSleeping(NewIsSleeping);
}