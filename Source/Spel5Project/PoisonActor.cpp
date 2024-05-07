// Fill out your copyright notice in the Description page of Project Settings.


#include "PoisonActor.h"
#include "Components/BoxComponent.h"

// Sets default values
APoisonActor::APoisonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 0.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

}

// Called when the game starts or when spawned
void APoisonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoisonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

