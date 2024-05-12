// Copyright Epic Games, Inc. All Rights Reserved.

#include "DevopsShowcaseGameMode.h"
#include "DevopsShowcaseHUD.h"
#include "DevopsShowcaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADevopsShowcaseGameMode::ADevopsShowcaseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADevopsShowcaseHUD::StaticClass();
}
