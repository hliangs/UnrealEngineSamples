// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../Interfaces/TInterface.h"
#include "TGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ABSTRACTANDINTERFACE_API UTGameInstance : public UGameInstance,public ITInterface
{
	GENERATED_BODY()
	//接口的实现需要在方法名后加 “_Implementation”
	//同样的向特定接口发送消息的时候要在方法名前加“Execute_”
	//检查某个类是否实现了某个接口使用UClass类的ImplementsInterface方法
	virtual bool Interface_function_Implementation(UObject* Object) override;
};
