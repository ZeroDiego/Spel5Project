#include "PushPullPawn.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APushPullPawn::APushPullPawn()
{
    // Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f));
    CollisionBox->SetCollisionProfileName("Trigger");
    RootComponent = CollisionBox;
    
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APushPullPawn::OnOverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APushPullPawn::OnOverlapEnd);

    bIsOverlapping = false;
    PlayerCharacter = nullptr;
}

// Called when the game starts or when spawned
void APushPullPawn::BeginPlay()
{
    Super::BeginPlay();
    
    // Ensure InputComponent is not null before setting up input
    if (InputComponent) {
        SetupPlayerInputComponent(InputComponent);
    } else {
        UE_LOG(LogTemp, Error, TEXT("InputComponent is null in BeginPlay."));
    }
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
    UE_LOG(LogTemp, Warning, TEXT("Setting up input component"));
    PlayerInputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &APushPullPawn::OnKeyDown);
}

void APushPullPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Overlap Begin with Push/Pull Object");
    bIsOverlapping = true;

    if (OtherActor->IsA(ACharacter::StaticClass()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Player Overlapping");
        PlayerCharacter = Cast<ACharacter>(OtherActor);
    }
}

void APushPullPawn::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End with Push/Pull Object");
    bIsOverlapping = false;
    PlayerCharacter = nullptr;
}

void APushPullPawn::OnKeyDown(FKey Key)
{
    UE_LOG(LogTemp, Warning, TEXT("OnKeyDown called with key: %s"), *Key.ToString());
    if (Key == EKeys::LeftMouseButton && bIsOverlapping && PlayerCharacter)
    {
        UE_LOG(LogTemp, Warning, TEXT("Button Pressed, moving player."));
        // Get the player's input
        const FVector PlayerInput = PlayerCharacter->GetInputAxisValue(FName("MoveForward")) * PlayerCharacter->GetActorForwardVector() +
                                PlayerCharacter->GetInputAxisValue(FName("MoveRight")) * PlayerCharacter->GetActorRightVector();

        // Move the PushPullPawn based on the player's input
        AddMovementInput(PlayerInput);
    }
}

// Implement movement functionality
void APushPullPawn::MoveForward(float Value)
{
    if (Value!= 0.0f)
    {
        // Add movement in that direction
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void APushPullPawn::MoveRight(float Value)
{
    if (Value!= 0.0f)
    {
        // Add movement in that direction
        AddMovementInput(GetActorRightVector(), Value);
    }
}