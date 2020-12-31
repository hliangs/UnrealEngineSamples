// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

UMyGameInstance::UMyGameInstance()
{
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}


bool UMyGameInstance::RequestOpenLevel(FName levelName)
{
	UGameplayStatics::OpenLevel(GetWorld(), levelName);
	return true;
}
