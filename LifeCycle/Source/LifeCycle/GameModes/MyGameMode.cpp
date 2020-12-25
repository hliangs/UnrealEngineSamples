// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "../LifeCycle.h"
AMyGameMode::AMyGameMode()
{
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

AMyGameMode::~AMyGameMode()
{
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}
