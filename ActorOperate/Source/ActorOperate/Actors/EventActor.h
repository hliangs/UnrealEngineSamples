// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventActor.generated.h"

UCLASS()
class ACTOROPERATE_API AEventActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventActor();

	UPROPERTY(EditAnywhere, Category = "RotActor")
	AActor* RotActor;

	UPROPERTY(VisibleAnywhere)
	FTimerHandle Handle;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void IKeyEvent();

	UFUNCTION()
	void VKeyEvent();

	UFUNCTION()
	void TimerEvent();
	
	virtual  void Destroyed() override;
};
