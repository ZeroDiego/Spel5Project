#include "Spel5Project/Public/PushPullActor.h"
#include "Engine/Engine.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Kismet/GameplayStatics.h"
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

void APushPullActor::BeginPlay()
{
	Super::BeginPlay();

	// Setup input component here
	SetupPlayerInputComponent(this->CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent")));
}

void APushPullActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind the PullObject action to the left mouse button press
	PlayerInputComponent->BindAction("PullObjectAction", IE_Pressed, this, &APushPullActor::PullObject);

	// Bind the ReleaseObject action to the left mouse button release
	PlayerInputComponent->BindAction("PullObjectAction", IE_Released, this, &APushPullActor::ReleaseObject);
}

void APushPullActor::PullObject(const FVector& PlayerLocation)
{
	if (!bIsGrabbed)
	{
		UE_LOG(LogTemp, Warning, TEXT("ISGRABBED"));
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

	// Check if the actor is being grabbed
	if (bIsGrabbed)
	{
		// Use the exposed PlayerBlueprintClass to find the player's pawn
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerBlueprintClass, FoundActors);

		// Assuming the first found actor is the player's pawn
		if (!FoundActors.IsEmpty())
		{
			const AActor* PlayerPawn = FoundActors[0];
			UE_LOG(LogTemp, Warning, TEXT("Found Player Pawn: %s"), *PlayerPawn->GetName());
			MeshComponent->SetupAttachment(PlayerPawn->GetRootComponent());
		}
	}
}