// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pot.generated.h"

UCLASS()
class SPEL5PROJECT_API APot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APot();
	
	bool GetIsPoisoned() const;
	
	void SetPoisoned(bool IsPoisoned);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	bool IsPoisoned;

};
