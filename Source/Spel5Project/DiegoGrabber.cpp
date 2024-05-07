// Fill out your copyright notice in the Description page of Project Settings.


#include "DiegoGrabber.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDiegoGrabber::UDiegoGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDiegoGrabber::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UDiegoGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UPhysicsHandleComponent *HandleComponent = GetPhysicsHandle();

	if (HandleComponent && HandleComponent->GetGrabbedComponent() != nullptr)
	{
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		HandleComponent->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}
}

void UDiegoGrabber::Release()
{
	UPhysicsHandleComponent * HandleComponent = GetPhysicsHandle();

	if (HandleComponent && HandleComponent->GetGrabbedComponent() != nullptr)
	{
		HandleComponent->GetGrabbedComponent()->WakeAllRigidBodies();
		HandleComponent->GetGrabbedComponent()->GetOwner()->Tags.Remove("Grabbed");
		HandleComponent->ReleaseComponent();
	}
}

void UDiegoGrabber::Grab()
{
	UPhysicsHandleComponent *HandleComponent = GetPhysicsHandle();

	if (HandleComponent == nullptr)
	{
		return;
	}
	FHitResult HitResult;
	if (GetGrabableInReach(HitResult))
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();
		HitComponent->WakeAllRigidBodies();
		HitResult.GetActor()->Tags.Add("Grabbed");
		HandleComponent->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation());
	}
}


UPhysicsHandleComponent* UDiegoGrabber::GetPhysicsHandle() const
{
	UPhysicsHandleComponent* Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle Needed"));
	}

	return Result;
}

bool UDiegoGrabber::GetGrabableInReach(FHitResult &OutHit) const
{
	FVector Start = GetComponentLocation();
	FVector End = GetComponentLocation() + GetForwardVector() * MaxGrabDistance;

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	return GetWorld()->SweepSingleByChannel(
		OutHit,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
		);
	
}

