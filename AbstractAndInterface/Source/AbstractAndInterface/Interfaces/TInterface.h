// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ABSTRACTANDINTERFACE_API ITInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Interface_function(UObject* Object);
};
