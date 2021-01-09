// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../Interfaces/MyInterface.h"
#include "../Interfaces/KeyInterface.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACTOROPERATE_API UMyGameInstance : public UGameInstance,public IMyInterface,public IKeyInterface
{
	GENERATED_BODY()
	
	virtual void OnStart() override;
	virtual int KeyPress_Implementation(FKey key) override;
	virtual bool KeyEvent_Implementation(FKey key) override;
	virtual bool RequestOpenlevel_Implementation(UObject* world, FName& name)override;
	
};
