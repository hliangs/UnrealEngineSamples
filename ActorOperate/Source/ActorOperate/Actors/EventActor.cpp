// Fill out your copyright notice in the Description page of Project Settings.


#include "EventActor.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyActor.h"
#include "../ActorOperate.h"
// Sets default values
AEventActor::AEventActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//按键事件响应
void AEventActor::IKeyEvent()
{
	int32 X = 320,rot = 0;
	for(;X > -320;X-=310)
		for(int Y = 300;Y > -300;Y-= 290){
			AMyActor* actor = GetWorld()->SpawnActor<AMyActor>(AMyActor::StaticClass(), FVector(X,Y,100), FRotator(rot += 40));
			actor->SetActorScale3D(FVector(0.5));
		}
}

// Called when the game starts or when spawned
void AEventActor::BeginPlay()
{
	Super::BeginPlay();
	//添加一个按键事件
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UInputComponent* Input = NewObject<UInputComponent>();
	Input->BindKey(EKeys::I, IE_Pressed, this, &AEventActor::IKeyEvent);
	Input->BindKey(EKeys::V, IE_Pressed, this, &AEventActor::VKeyEvent);
	Controller->PushInputComponent(Input);

	
}

void AEventActor::TimerEvent()
{
	RotActor->AddActorLocalRotation(FRotator(5, 0, 0));
	UE_LOG(MyLog, Warning, TEXT(__FUNCTION__));
}

void AEventActor::VKeyEvent()
{
	//添加一个定时器，为了设置场景的一个Actor旋转
	if(!Handle.IsValid())
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AEventActor::TimerEvent, 1.0f, true);
	UE_LOG(MyLog, Warning, TEXT(__FUNCTION__));
}

void AEventActor::Destroyed()
{
	if(Handle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(Handle);
	}
}

// Called every frame
void AEventActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

