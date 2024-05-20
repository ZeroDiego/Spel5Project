// Diego Puentes Varas dipu6255

#include "OwnerCharacter.h"

AOwnerCharacter::AOwnerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AOwnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOwnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOwnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AOwnerCharacter::GetIsAlerted() const
{
	return IsAlerted;
}

void AOwnerCharacter::SetIsAlerted(const bool NewIsAlerted)
{
	IsAlerted = NewIsAlerted;
}

FVector AOwnerCharacter::GetLastKnownPlayerLocation() const
{
	return LastKnownPlayerLocation;
}

void AOwnerCharacter::SetLastKnownPlayerLocation(const FVector& NewLastKnownPlayerLocation)
{
	LastKnownPlayerLocation = NewLastKnownPlayerLocation;
}
/*
void AOwnerCharacter::KillPlayer() const
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("DiegoJacobLevel"), true);
}
*/