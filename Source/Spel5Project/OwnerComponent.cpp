// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerComponent.h"

// Sets default values for this component's properties
UOwnerComponent::UOwnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	if (AActor* OwnerActor = GetOwner())
	{
		if (ACharacter* CharacterInstance = Cast<ACharacter>(OwnerActor))
		{
			if (AOwnerCharacter* OwnerCharacterInstance = Cast<AOwnerCharacter>(CharacterInstance))
				OwnerCharacter = OwnerCharacterInstance;
		}
	}
}


// Called when the game starts
void UOwnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOwnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UOwnerComponent::SetOwner(AOwnerCharacter* NewOwnerCharacter)
{
	OwnerCharacter = NewOwnerCharacter;
}

bool UOwnerComponent::GetOwnerIsAlerted() const
{
	return OwnerCharacter->GetIsAlerted();
}
