// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SF.h"
#include "SFGameMode.h"
#include "SFHUD.h"
#include "SFCharacter.h"

ASFGameMode::ASFGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/FirstPersonCPP/Blueprints/BP_SFCharacter'"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASFHUD::StaticClass();
}
