// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "TLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class ABSTRACTANDINTERFACE_API ATLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
};
