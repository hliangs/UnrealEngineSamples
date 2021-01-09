// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class LOG_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	UPROPERTY()
	class UInputComponent* Input;
	UFUNCTION()
	void UKeyEvent();
	UFUNCTION()
	void IKeyEvent();
	UFUNCTION()
	void OKeyEvent();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual  void Destroyed() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
