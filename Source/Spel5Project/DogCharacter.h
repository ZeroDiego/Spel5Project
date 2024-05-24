// Diego Puentes Varas dipu6255

#pragma once

#include "CoreMinimal.h"
#include "Mover.h"
#include "GameFramework/Character.h"
#include "DogCharacter.generated.h"

UCLASS()
class SPEL5PROJECT_API ADogCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADogCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(Blueprintable)
	bool GetIsBarking() const;
	
	void SetIsBarking(bool NewIsBarking);
	
	UFUNCTION(Blueprintable)
	bool GetIsSatisfied() const;
	
	void SetIsSatisfied(bool NewIsSatisfied);

	UFUNCTION(Blueprintable)
	bool GetIsEating() const;
	
	void SetIsEating(bool NewIsEating);

	UFUNCTION(Blueprintable)
	bool GetIsDoorOpen() const;
	
	void SetIsDoorOpen(bool NewIsDoorOpen);

	UFUNCTION(Blueprintable)
	bool GetIsSleeping() const;
	
	void SetIsSleeping(bool NewIsSleeping);

	void Alert() const;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UMover* GetMover() const;
	
	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* NewMover);
	
private:
	UPROPERTY(VisibleAnywhere)
	bool IsBarking;
	
	UPROPERTY(VisibleAnywhere)
	bool IsSatisfied;
	
	UPROPERTY(VisibleAnywhere)
	bool IsEating;

	UPROPERTY(VisibleAnywhere)
	bool IsDoorOpen;

	UPROPERTY(VisibleAnywhere)
	bool IsSleeping;

	UPROPERTY(VisibleAnywhere)
	bool IsAlert;
	
	UPROPERTY(EditAnywhere)
	float SleepDelay = 1;
	
	UPROPERTY(EditAnywhere)
	USoundBase* BarkSound;

	UPROPERTY(EditAnywhere)
	USoundBase* EatSound;
	
	FTimerHandle SleepTimer;

	UMover* Mover;
};