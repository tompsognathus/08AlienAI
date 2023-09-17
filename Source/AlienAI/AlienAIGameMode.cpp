// Copyright Epic Games, Inc. All Rights Reserved.

#include "AlienAIGameMode.h"
#include "AlienAICharacter.h"
#include "UObject/ConstructorHelpers.h"

AAlienAIGameMode::AAlienAIGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
