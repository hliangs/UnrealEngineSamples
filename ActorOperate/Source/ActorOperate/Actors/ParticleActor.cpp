// Fill out your copyright notice in the Description page of Project Settings.


#include "ParticleActor.h"
#include "Components/ArrowComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AParticleActor::AParticleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UArrowComponent* ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	RootComponent = ArrowComp;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> Finder(TEXT("ParticleSystem'/Game/Niagara/Fountain.Fountain'"));
	UParticleSystemComponent* ParticleSystemComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComp"));
	
	if(Finder.Succeeded())
	{
		ParticleSystem = Finder.Object;
		ParticleSystemComp->SetupAttachment(RootComponent);
		ParticleSystemComp->Template = ParticleSystem;
	}
}

// Called when the game starts or when spawned
void AParticleActor::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	UInputComponent* InputComp = NewObject<UInputComponent>();
	InputComp->BindKey(EKeys::U, IE_Pressed, this, &AParticleActor::UKeyEvent);
	PlayerController->PushInputComponent(InputComp);
	FOnTimelineFloatStatic TimelineCallback;
	TimelineCallback.BindUFunction(this, FName("TimeLineCallBack"));
	Timeline.AddInterpFloat(CurveFloat,TimelineCallback);
	Timeline.SetLooping(true);
}
void AParticleActor::TimeLineCallBack(float time)
{
	UE_LOG(LogTemp, Error, TEXT("time line value is %f"), time);
	static VectorRegister A, B;
	FRotator Posion = UKismetMathLibrary::RLerp(FRotator(45.0f, 0.0f, 0.0f), FRotator(-45.0f, 0.0f, 0.0f), time,false);
	RootComponent->SetWorldRotation(Posion);
}
void AParticleActor::UKeyEvent()
{
	Timeline.Play();
}
// Called every frame
void AParticleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);
}

