#include "Spel5Project/Public/PushPullActor.h"
#include "Engine/Engine.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/BoxComponent.h"


APushPullActor::APushPullActor()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
    MeshComponent->SetSimulatePhysics(true);
    MeshComponent->SetLinearDamping(2.f);
    SetRootComponent(MeshComponent);

    // Create a physics constraint component to restrict the actor's movement.
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

void APushPullActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check if both bOwnerOverlapping and bCharOverlapping are true
    if (bOwnerOverlapping && bCharOverlapping)
    {
        DisablePhysics();
    }
    else
    {
        EnablePhysics();
    }
}

void APushPullActor::EnablePhysics()
{
    MeshComponent->SetSimulatePhysics(true);
}

void APushPullActor::DisablePhysics()
{
    MeshComponent->SetSimulatePhysics(false);
}