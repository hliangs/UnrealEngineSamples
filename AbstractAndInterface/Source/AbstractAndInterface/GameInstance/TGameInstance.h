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
	//�ӿڵ�ʵ����Ҫ�ڷ�������� ��_Implementation��
	//ͬ�������ض��ӿڷ�����Ϣ��ʱ��Ҫ�ڷ�����ǰ�ӡ�Execute_��
	//���ĳ�����Ƿ�ʵ����ĳ���ӿ�ʹ��UClass���ImplementsInterface����
	virtual bool Interface_function_Implementation(UObject* Object) override;
};
