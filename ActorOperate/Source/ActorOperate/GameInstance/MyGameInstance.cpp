// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
void UMyGameInstance::OnStart()
{
	Super::OnStart();
	UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
}

int UMyGameInstance::KeyPress_Implementation(FKey key)
{
	UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
	return 0;
}

bool UMyGameInstance::KeyEvent_Implementation(FKey key)
{
	UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
	return true;
}

bool UMyGameInstance::RequestOpenlevel_Implementation(UObject* world, FName& name)
{
	UGameplayStatics::OpenLevel(world, name);
	return false;
}

