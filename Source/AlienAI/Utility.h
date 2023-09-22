// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AAlienAICharacter;
class AAlienAIController;
class UBehaviorTreeComponent;
class UNavigationSystemV1;

class ALIENAI_API Utility
{
public:

	// Player
	static APlayerController* GetFirstPlayerController(UObject* Object);
	static APawn* GetPlayerPawn(UObject* Object);
	static AAlienAICharacter* GetPlayerCharacter(UObject* Object);

	// Aliens
	static AAlienAIController* GetAlienController(UBehaviorTreeComponent& OwnerComponent);
	static APawn* GetAlienPawn(UBehaviorTreeComponent& OwnerComponent);

	// Navigation
	static UNavigationSystemV1* GetNavigationSystem(UObject* Object);

};
