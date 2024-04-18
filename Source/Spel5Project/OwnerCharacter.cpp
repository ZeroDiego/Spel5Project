// Fill out your copyright notice in the Description page of Project Settings.


#include "OwnerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOwnerCharacter::AOwnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOwnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOwnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
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

void AOwnerCharacter::KillPlayer() const
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("DiegoJacobLevel"), true);
}
