// Fill out your copyright notice in the Description page of Project Settings.


#include "TLevelScriptActor.h"
#include "Kismet/GameplayStatics.h"
#include "../GameInstance/TGameInstance.h"
#include "../Interfaces/TInterface.h"
void ATLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	UTGameInstance* Instance = Cast<UTGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Instance&&Instance->GetClass()->ImplementsInterface(UTInterface::StaticClass()))
	{
		UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
		ITInterface* Interface = Cast<ITInterface>(Instance);
		NewObject<UObject>(this);
		Interface->Execute_Interface_function(Instance, Instance);
	}
	
}
