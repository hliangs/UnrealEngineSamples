// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Interfaces/KeyEvents.h"
#include "TUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ACTOROPERATE_API UTUserWidget : public UUserWidget,public IKeyEvents
{
	GENERATED_BODY()

	virtual bool KeyEvents_Implementation(FKey key) override;
};
