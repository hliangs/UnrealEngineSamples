// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "../LifeCycle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
	;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	static bool bTog = false;
	if(!bTog)
	{
		UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
		bTog= !bTog;
	}
}

void AMyActor::Destroyed()
{
	Super::Destroyed();
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

void AMyActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

