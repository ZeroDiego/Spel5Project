#include "Spel5Project/Public/PushPullActor.h"
#include "Engine/Engine.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

APushPullActor::APushPullActor()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetLinearDamping(2.f);
	SetRootComponent(MeshComponent);

	PhysicsComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>("PhysicsComponent");
	PhysicsComponent->SetLinearXLimit(LCM_Free, 0.f);
	PhysicsComponent->SetLinearYLimit(LCM_Free, 0.f);
	PhysicsComponent->SetAngularSwing1Limit(ACM_Locked, 0.f);
	PhysicsComponent->SetAngularSwing2Limit(ACM_Locked, 0.f);
	PhysicsComponent->SetAngularTwistLimit(ACM_Locked, 0.f);
	FConstrainComponentPropName ComponentPropName;
	ComponentPropName.ComponentName = "MeshComponent";
	PhysicsComponent->ComponentName1 = ComponentPropName;
	PhysicsComponent->SetupAttachment(MeshComponent);

	PhysicsHandleComponent = CreateDefaultSubobject<UPhysicsHandleComponent>("PhysicsHandleComponent");

	Tags.Add("movable");
}

void APushPullActor::PullObject(const FVector& PlayerLocation)
{
	if (!bIsGrabbed)
	{
		bIsGrabbed = true;
		GrabLocation = PlayerLocation;
		PhysicsHandleComponent->GrabComponentAtLocationWithRotation(MeshComponent, NAME_None, GrabLocation, MeshComponent->GetComponentRotation());
	}
}

void APushPullActor::ReleaseObject()
{
	if (bIsGrabbed)
	{
		bIsGrabbed = false;
		PhysicsHandleComponent->ReleaseComponent();
	}
}

void APushPullActor::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsGrabbed)
	{
		const FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		PhysicsHandleComponent->SetTargetLocation(PlayerLocation);
	}
}