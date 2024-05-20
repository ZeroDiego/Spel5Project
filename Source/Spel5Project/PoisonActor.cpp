// Fill out your copyright notice in the Description page of Project Settings.


#include "PoisonActor.h"
#include "Components/BoxComponent.h"

APoisonActor::APoisonActor()
{

	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 0.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

}

void APoisonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void APoisonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

