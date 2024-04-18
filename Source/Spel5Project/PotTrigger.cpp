#include "PotTrigger.h"

UPotTrigger::UPotTrigger()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPotTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void UPotTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* PoisonActor = GetPoisonActor();
	if (PoisonActor != nullptr)
	{
		Pot->SetPoisoned(true);
		PoisonActor->Destroy();
	}
}

void UPotTrigger::SetPot(APot* NewPot)
{
	Pot = NewPot;
}

AActor* UPotTrigger::GetPoisonActor() const
{
	TArray<AActor*> Actors;
	AActor* OwnerActor = GetOwner();
	if (OwnerActor)
	{
		OwnerActor->GetOverlappingActors(Actors);

		for (AActor* Actor : Actors)
		{
			if (Actor->ActorHasTag(PoisonTag))
			{
				return Actor;
			}
		}
	}

	return nullptr;
}