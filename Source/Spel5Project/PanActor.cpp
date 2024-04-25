// Fill out your copyright notice in the Description page of Project Settings.


#include "PanActor.h"

#include "AI_Owner.h"
#include "PoisonActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

// Sets default values
APanActor::APanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APanActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APanActor::OnOverlapEnd);

	bIsOverlapping = false;
	isPoisoned = false;

}

// Called when the game starts or when spawned
void APanActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APanActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APanActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(APoisonActor::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlap Begin with Poison Object");
		bIsOverlapping = true;
		isPoisoned = true;
		OtherActor->Destroy();
	}
}

void APanActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APoisonActor::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End with Poison Object");
		bIsOverlapping = false;
	}
}

