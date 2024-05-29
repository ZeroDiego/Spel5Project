// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoisonActor.generated.h"

UCLASS()
class SPEL5PROJECT_API APoisonActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APoisonActor();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent * CollisionBox;

};
