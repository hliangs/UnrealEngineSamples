// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "../LifeCycle.h"
AMyGameMode::AMyGameMode()
{
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

void AMyGameMode::BeginDestroy()
{
	Super::BeginDestroy();
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AMyGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
