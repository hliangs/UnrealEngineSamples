// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/InputComponent.h"
#include "Engine/Texture2D.h"
#include "../ResLoad.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
// Sets default values
AMyActor::AMyActor()
{

	PrimaryActorTick.bCanEverTick = true;
	UBoxComponent* Box = CreateDefaultSubobject<UBoxComponent>(TEXT("UBoxComponent"));
	Box->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UTexture2D> FinderObject(TEXT("Texture2D'/Game/picture.picture'"));
	if(FinderObject.Succeeded())
	{
		m_Texture2D = FinderObject.Object;
		UE_LOG(MyLog, Warning, TEXT("Load m_Texture2D Success"));
	}else
	{
		UE_LOG(MyLog, Warning, TEXT("Load m_Texture2D Faild"));
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> FinderObjectX(TEXT("/Game/picture.picture"));
	if (FinderObjectX.Succeeded())
	{
		m_Texture2D = FinderObject.Object;
		UE_LOG(MyLog, Warning, TEXT("Load m_Texture2D Success"));
	}
	else
	{
		UE_LOG(MyLog, Warning, TEXT("Load m_Texture2D Faild"));
	}

	
	
	static ConstructorHelpers::FClassFinder<AActor> FinderBPClass(TEXT("Blueprint'/Game/BP_loadActor.BP_loadActor_C'"));
	if(FinderBPClass.Succeeded())
	{
		m_LoadActor = FinderBPClass.Class;
		UE_LOG(MyLog, Warning, TEXT("Load m_LoadActor Success"));
	}else
	{
		UE_LOG(MyLog, Warning, TEXT("Load m_LoadActor Faild"));
	}
	
	
}




// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//添加一个按键事件(U键)
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UInputComponent* InputComp = NewObject<UInputComponent>();
	InputComp->BindKey(EKeys::U, IE_Pressed, this, &AMyActor::UKeyEvent);
	Controller->PushInputComponent(InputComp);
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//按键事件响应
void AMyActor::UKeyEvent()
{
	UClass* AClass = LoadClass<ALoadActor>(this, TEXT("Blueprint'/Game/BP_loadActor.BP_loadActor_C'"));
	if (AClass)
	{
		UE_LOG(MyLog, Warning, TEXT("Load UClass Success"));
	}
	
	UTexture2D* _Texture2D = LoadObject<UTexture2D>(this, TEXT("Texture2D'/Game/picture.picture'"));
	if(_Texture2D)
	{
		UE_LOG(MyLog, Warning, TEXT("Load _Texture2D Success"));
	}

	UTexture2D* _Texture2DX = LoadObject<UTexture2D>(this, TEXT("/Game/picture"));
	if(_Texture2DX)
	{
		UE_LOG(MyLog, Warning, TEXT("Load _Texture2DX Success"));
	}
	
}


