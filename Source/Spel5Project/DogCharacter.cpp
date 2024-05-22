// Diego Puentes Varas dipu6255

#include "DogCharacter.h"
#include "Kismet/GameplayStatics.h"

ADogCharacter::ADogCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADogCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADogCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

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
	IsSatisfied = NewIsSatisfied;
}

bool ADogCharacter::GetIsSleeping() const
{
	return IsSleeping;
}

void ADogCharacter::SetIsSleeping(const bool NewIsSleeping)
{
	IsSleeping = NewIsSleeping;
}

bool ADogCharacter::GetHasEaten() const
{
	return HasEaten;
}

void ADogCharacter::SetHasEaten(const bool NewHasEaten)
{
	HasEaten = NewHasEaten;
	UGameplayStatics::SpawnSoundAttached(EatSound, GetMesh(), TEXT("Eat"));
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