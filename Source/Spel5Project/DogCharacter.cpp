// Fill out your copyright notice in the Description page of Project Settings.


#include "DogCharacter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ADogCharacter::ADogCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADogCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADogCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADogCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ADogCharacter::GetIsSatisfied() const
{
	return IsSatisfied;
}

void ADogCharacter::SetSatisfied(const bool NewIsSatisfied)
{
	UGameplayStatics::SpawnSoundAttached(EatSound, GetMesh(), TEXT("Eat"));
	IsSatisfied = NewIsSatisfied;
}

void ADogCharacter::Sleep()
{
	IsSleeping = true;
}

void ADogCharacter::Alert()
{
	IsAlert = true;
	UGameplayStatics::SpawnSoundAttached(BarkSound, GetMesh(), TEXT("Bark"));
}

UMover* ADogCharacter::GetMover() const
{
	return Mover;
}

void ADogCharacter::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}