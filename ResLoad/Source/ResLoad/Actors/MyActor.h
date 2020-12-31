// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadActor.h"
#include "MyActor.generated.h"

UCLASS()
class RESLOAD_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	
	UPROPERTY(EditAnywhere, Category = "Texture")
	UTexture2D* m_Texture2D;

	UPROPERTY(VisibleAnywhere, Category = "LoadActor")
	TSubclassOf<ALoadActor> m_LoadActor;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void UKeyEvent();
	
	void LoadRes();

};
