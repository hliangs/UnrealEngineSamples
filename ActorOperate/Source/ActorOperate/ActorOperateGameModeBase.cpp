// Copyright Epic Games, Inc. All Rights Reserved.


#include "ActorOperateGameModeBase.h"
#include "PlayerController/MyPlayerController.h"

AActorOperateGameModeBase::AActorOperateGameModeBase()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
