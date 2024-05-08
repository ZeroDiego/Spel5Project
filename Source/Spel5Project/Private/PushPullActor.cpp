#include "Spel5Project/Public/PushPullActor.h"
#include "Engine/Engine.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/Character.h"

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

void APushPullActor::BeginPlay()
{
    Super::BeginPlay();
}

void APushPullActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // Bind actions to the actor's methods
    // Bind the PullObject action to the left mouse button press
    PlayerInputComponent->BindAction("PullObjectAction", IE_Pressed, this, &APushPullActor::OnPullObjectPressed);

    // Bind the ReleaseObject action to the left mouse button release
    PlayerInputComponent->BindAction("PullObjectAction", IE_Released, this, &APushPullActor::OnReleaseObjectReleased);
}

void APushPullActor::OnPullObjectPressed()
{
    if (!bIsGrabbed)
    {
        UE_LOG(LogTemp, Warning, TEXT("ISGRABBED"));
        bIsGrabbed = true;
        // Obtain PlayerLocation within the method if necessary
        PhysicsHandleComponent->GrabComponentAtLocationWithRotation(MeshComponent, NAME_None, MeshComponent->GetComponentLocation(), MeshComponent->GetComponentRotation());
    }
}

void APushPullActor::OnReleaseObjectReleased()
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

    // Check if the actor is being grabbed
    if (bIsGrabbed && PlayerBlueprintClass!= nullptr)
    {
        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerBlueprintClass, FoundActors);

        if (!FoundActors.IsEmpty())
        {
            const AActor* PlayerPawn = FoundActors[0];
            MeshComponent->SetupAttachment(PlayerPawn->GetRootComponent());
            UE_LOG(LogTemp, Warning, TEXT("FOUND ACTOR"));
        }
    }
}

void APushPullActor::SetPlayerBlueprintClass(TSubclassOf<ACharacter> NewPlayerBlueprintClass)
{
    PlayerBlueprintClass = NewPlayerBlueprintClass;
}