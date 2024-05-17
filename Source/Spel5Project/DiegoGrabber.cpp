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

	if (const UPhysicsHandleComponent *HandleComponent = GetPhysicsHandle(); HandleComponent && HandleComponent->GetGrabbedComponent() != nullptr)
	{
		if (UPrimitiveComponent* GrabbedComponent = Cast<UPrimitiveComponent>(HandleComponent->GetGrabbedComponent()))
		{
			// Update the position of the grabbed actor to follow the grabber component
			const FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
			const FRotator TargetRotation = GetComponentRotation();

			// Set the position and rotation of the grabbed actor
			GrabbedComponent->SetWorldLocation(TargetLocation);
			GrabbedComponent->SetWorldRotation(TargetRotation);
		}
	}
}
/*
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
*/
bool UDiegoGrabber::Grab()
{
	if (UPhysicsHandleComponent *HandleComponent = GetPhysicsHandle(); HandleComponent == nullptr)
	{
		return false;
	}
	
	if (FHitResult HitResult; GetGrabableInReach(HitResult))
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();

		// Attach the grabbed actor to the grabber component
		if (AActor* HitActor = HitResult.GetActor())
		{
			// Store the original transform of the grabbed actor
			FTransform OriginalTransform = HitActor->GetTransform();

			// Disable physics simulation on the grabbed actor
			HitComponent->SetSimulatePhysics(false);

			// Detach the grabbed actor from its current parent
			HitActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

			// Attach the grabbed actor to this grabber component
			HitComponent->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetIncludingScale);

			// Add tag to the grabbed actor to indicate it's being grabbed
			HitActor->Tags.Add("Grabbed");

			// Store the offset from this grabber component to the grabbed actor
			FVector Offset = OriginalTransform.GetLocation() - GetComponentLocation();
			FRotator RotationOffset = (OriginalTransform.GetRotation().Rotator() - GetComponentRotation()).GetNormalized();

			// Re-parent the grabbed actor to this grabber component
			HitActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
			HitActor->SetActorRelativeLocation(Offset);
			HitActor->SetActorRelativeRotation(RotationOffset);

			return true;
		}
	}

	return false;
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
	const FVector Start = GetComponentLocation();
	const FVector End = GetComponentLocation() + GetForwardVector() * MaxGrabDistance;

	const FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	return GetWorld()->SweepSingleByChannel(
		OutHit,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
		);
}