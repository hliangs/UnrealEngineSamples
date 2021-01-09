// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractClass.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ABSTRACTANDINTERFACE_API UAbstractClass : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION()
	virtual bool Switch(int& type);
};
