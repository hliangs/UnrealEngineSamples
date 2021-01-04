// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"
#include "ParticleActor.generated.h"


UCLASS()
class ACTOROPERATE_API AParticleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParticleActor();
	UPROPERTY(EditAnywhere, Category = "Particle System")
	UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Curve")
	UCurveFloat* CurveFloat;

	UFUNCTION()
	void UKeyEvent();

	UFUNCTION()
	void TimeLineCallBack(float time);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere,Category="Time Line")
	FTimeline Timeline;


};
