// Fill out your copyright notice in the Description page of Project Settings.


#include "DogTrigger.h"

UDogTrigger::UDogTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UDogTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UDogTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Actor = GetMeatActor();
	if (Actor != nullptr)
	{
		DogCharacter->SetIsEating(true);
		Actor->Destroy();
	}
}

void UDogTrigger::SetDog(ADogCharacter* NewDogCharacter)
{
	DogCharacter = NewDogCharacter;
}

AActor* UDogTrigger::GetMeatActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(MeatTag))
		{
			return Actor;
		}
	}

	return nullptr;
}
