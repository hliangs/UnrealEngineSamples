// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "..\ActorOperate.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneCaptureComponent2D.h"
#include "../GameInstance/MyGameInstance.h"
#include "../Interfaces/MyInterface.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UStaticMeshComponent* MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("comp"));
	RootComponent = SceneComp;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Finder(TEXT("StaticMesh'/Game/Box.Box'"));
	if(Finder.Succeeded())
	{
		MeshComp->SetStaticMesh(Finder.Object);
	}
	MeshComp->SetupAttachment(RootComponent);

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	SceneCapture->SetupAttachment(RootComponent);
}

void AMyActor::UKeyEvent()
{
	UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
}

void AMyActor::CKeyEvent()
{
	UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(),0);
	Controller->bBlockInput = false;
	UInputComponent* Input = NewObject<UInputComponent>(this);
	Input->bBlockInput = false;
	Input->BindKey(EKeys::U, IE_Pressed, this, &AMyActor::UKeyEvent);
	Input->BindKey(EKeys::C, IE_Pressed, this, &AMyActor::CKeyEvent);
	Controller->PushInputComponent(Input);
	UMyGameInstance*Instance =Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())) ;
	if (Instance&&Instance->GetClass()->ImplementsInterface(UMyInterface::StaticClass()))
	{
		IMyInterface* Interface = Cast<IMyInterface>(Instance);
		UE_LOG(LogTemp, Error, TEXT(__FUNCTION__));
		Interface->Execute_KeyPress(Instance,EKeys::U);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

