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
    MeshComponent->SetLinearDamping(0.f);
    MeshComponent->SetAngularDamping(0.f);
    SetRootComponent(MeshComponent);

    // Create a physics constraint component to restrict the actor's movement.
    PhysicsComponent = CreateDefaultSubobject<UPhysicsConstraintComponent>("PhysicsComponent");
    PhysicsComponent->SetLinearXLimit(LCM_Free, 0.f);
    PhysicsComponent->SetLinearYLimit(LCM_Free, 0.f);
    PhysicsComponent->SetLinearZLimit(LCM_Locked, 0.f);
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

/*void APushPullActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}*/

void APushPullActor::EnablePhysics()
{
    MeshComponent->SetSimulatePhysics(true);
    UE_LOG(LogTemp, Warning, TEXT("Physics Enabled"));
}

void APushPullActor::DisablePhysics()
{
    MeshComponent->SetSimulatePhysics(false);
    UE_LOG(LogTemp, Warning, TEXT("Physics Disabled"));
}