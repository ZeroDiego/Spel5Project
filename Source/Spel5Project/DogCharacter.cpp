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

bool ADogCharacter::GetIsBarking() const
{
	return IsBarking;
}

void ADogCharacter::SetIsBarking(const bool NewIsBarking)
{
	IsBarking = NewIsBarking;
}

bool ADogCharacter::GetIsSatisfied() const
{
	return IsSatisfied;
}

void ADogCharacter::SetIsSatisfied(const bool NewIsSatisfied)
{
	IsSatisfied = NewIsSatisfied;
}

bool ADogCharacter::GetIsEating() const
{
	return IsEating;
}

void ADogCharacter::SetIsEating(const bool NewIsEating)
{
	IsEating = NewIsEating;
	UGameplayStatics::SpawnSoundAttached(EatSound, GetMesh(), TEXT("Eat"));
}

bool ADogCharacter::GetIsDoorOpen() const
{
	return IsDoorOpen;
}

void ADogCharacter::SetIsDoorOpen(const bool NewIsDoorOpen)
{
	IsDoorOpen = NewIsDoorOpen;
}

bool ADogCharacter::GetIsSleeping() const
{
	return IsSleeping;
}

void ADogCharacter::SetIsSleeping(const bool NewIsSleeping)
{
	IsSleeping = NewIsSleeping;
}

void ADogCharacter::Alert() const
{
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