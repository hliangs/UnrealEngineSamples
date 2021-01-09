// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "../Log.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::UKeyEvent()
{
	UE_LOG(MyLog, Log, TEXT(__FUNCTION__));
	UE_LOG(MyLog, Warning, TEXT(__FUNCTION__));
	
	
}

void AMyActor::IKeyEvent()
{
	UE_LOG(MyLogD, VeryVerbose, TEXT(__FUNCTION__));
}

void AMyActor::OKeyEvent()
{
	if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT(__FUNCTION__));

}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	Input = NewObject<UInputComponent>(this);
	Input->bBlockInput = false;
	Input->BindKey(EKeys::U, IE_Pressed, this, &AMyActor::UKeyEvent);
	Input->BindKey(EKeys::I, IE_Pressed, this, &AMyActor::IKeyEvent);
	Input->BindKey(EKeys::O, IE_Pressed, this, &AMyActor::OKeyEvent);
	Controller->PushInputComponent(Input);
	
}

void AMyActor::Destroyed()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(Controller)
		Controller->PopInputComponent(Input);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

