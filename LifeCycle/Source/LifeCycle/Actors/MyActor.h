// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/SceneCapture2D.h"
#include "MyActor.generated.h"


UCLASS(HideCategories=("ActorArray|Num"))
class LIFECYCLE_API AMyActor : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AMyActor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Destroyed() override;
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
