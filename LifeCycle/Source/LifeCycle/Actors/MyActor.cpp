// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "../LifeCycle.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
// Sets default values
AMyActor::AMyActor()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//USphereComponent* comp = CreateDefaultSubobject<USphereComponent>(TEXT("USphereComponent"));
	UBoxComponent* comps = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = comps;
	comps->InitBoxExtent(FVector(5, 5, 5));
	//comp->InitSphereRadius(60.0f);
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));

}

AMyActor::~AMyActor()
{
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
}

void AMyActor::MyFunc()
{
	static FRotator v(0, 0, 5);
	act->AddActorLocalRotation(v);
}

void AMyActor::Input()
{
	static bool Active = false;
	if (!handle.IsValid())
		GetWorldTimerManager().SetTimer(handle, this, &AMyActor::MyFunc, 1.0f, true);
	if(handle.IsValid())
		if (Active )
			GetWorldTimerManager().PauseTimer(handle);
		else 
			GetWorldTimerManager().UnPauseTimer(handle);
	
	Active = !Active;
	UE_LOG(LifeCycle, Warning, TEXT(__FUNCTION__));
	
	
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	
	APlayerController* Conl =  UGameplayStatics::GetPlayerController(GetWorld(),0);
	if(Conl)
	{
		UInputComponent* cop = NewObject<UInputComponent>();
		cop->BindKey(EKeys::U, IE_Pressed, this, &AMyActor::Input);
		Conl->PushInputComponent(cop);
	
	}

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

