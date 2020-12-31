// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../LifeCycle.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LIFECYCLE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();

	UFUNCTION(BlueprintCallable)
	bool RequestOpenLevel(FName levelName);
	
};
