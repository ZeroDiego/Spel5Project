// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Owner.h"

// Sets default values
AAI_Owner::AAI_Owner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Owner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Owner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Owner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* AAI_Owner::GetBehaviorTree() const
{
	return Tree;
}

