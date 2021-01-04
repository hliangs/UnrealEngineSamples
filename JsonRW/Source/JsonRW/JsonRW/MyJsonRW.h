// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Serialization/JsonTypes.h"
#include "MyJsonRW.generated.h"

UCLASS()
class JSONRW_API AMyJsonRW : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyJsonRW();

	UFUNCTION(BlueprintCallable)
	void WriteJson();

	UFUNCTION(BlueprintCallable)
	void ReadJson(FString&path,FString& Field,FString& value);
	
	UFUNCTION()
	void UKeyEvent();
	
	UFUNCTION()
	void IKeyEvent();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
