// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NewObject<AActor>();
	static ConstructorHelpers::FClassFinder<AActor> Finder(TEXT(""));
	if(Finder.Succeeded())
	{
		TSubclassOf<AActor> a = Finder.Class;
	}
	//UGameplayStatics::SpawnObject()
	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->SpawnActor<AActor>(AActor::StaticClass(), FVector(0.0f, 0.0f, 0), FRotator(0, 0, 0), FActorSpawnParameters());
	GetWorld()->SpawnActor<AActor>();
	UClass* xxx = LoadClass<AActor>(this,TEXT("ss"));
	
	Cast<AActor>(LoadObject<AActor>(this, TEXT("XX")));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

