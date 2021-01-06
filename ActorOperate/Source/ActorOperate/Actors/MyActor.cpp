// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "..\ActorOperate.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneCaptureComponent2D.h"
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


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

