// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "../LifeCycle.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LIFECYCLE_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AMyGameMode();
	~AMyGameMode();
};
