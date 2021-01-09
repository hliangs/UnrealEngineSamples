// Copyright Epic Games, Inc. All Rights Reserved.

#include "Log.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Log, "Log" );
DEFINE_LOG_CATEGORY(MyLog);
DEFINE_LOG_CATEGORY(MyLogD);