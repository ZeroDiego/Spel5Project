// Fill out your copyright notice in the Description page of Project Settings.


#include "PushPullPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"

// Sets default values
APushPullPawn::APushPullPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
	CollisionBox->SetCollisionProfileName("Trigger");
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APushPullPawn::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APushPullPawn::OnOverlapEnd);

	bIsOverlapping = false;

}

// Called when the game starts or when spawned
void APushPullPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APushPullPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APushPullPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APushPullPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlap Begin with Push/Pull Object");
		bIsOverlapping = true;

	if (OtherActor->IsA(ACharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Player Overlapping");
		bIsOverlapping = true;
	}
}

void APushPullPawn::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End with Push/Pull Object");
		bIsOverlapping = false;
}