// Fill out your copyright notice in the Description page of Project Settings.


#include "Utility.h"
#include "AlienAICharacter.h"
#include "AlienAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


APlayerController* Utility::GetFirstPlayerController(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetFirstPlayerController: Invalid World"));
		return nullptr;
	}

	APlayerController* FirstPlayerController = World->GetFirstPlayerController();
	if (!IsValid(FirstPlayerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetFirstPlayerController: FirstPlayerController is not valid"));
		return nullptr;
	}

	return FirstPlayerController;
}

APawn* Utility::GetPlayerPawn(UObject* Object)
{
	APlayerController* FirstPlayerController = Utility::GetFirstPlayerController(Object);
	if (!IsValid(FirstPlayerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetPlayerPawn:  FirstPlayerController is not valid"));
		return nullptr;
	}

	APawn* PlayerPawn = FirstPlayerController->GetPawn();
	if (!IsValid(PlayerPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetPlayerPawn: Invalid PlayerPawn"));
		return nullptr;
	}

	return PlayerPawn;
}

AAlienAICharacter* Utility::GetPlayerCharacter(UObject* Object)
{
	APawn* PlayerPawn = Utility::GetPlayerPawn(Object);
	AAlienAICharacter* PlayerCharacter = Cast<AAlienAICharacter>(PlayerPawn);

	if (!IsValid(PlayerCharacter))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetPlayerCharacter: Invalid PlayerCharacter"));
		return nullptr;
	}

	return PlayerCharacter;
}


AAlienAIController* Utility::GetAlienController(UBehaviorTreeComponent& OwnerComponent)
{
	AAlienAIController* const AlienController = Cast<AAlienAIController>(OwnerComponent.GetAIOwner());
	if (!IsValid(AlienController))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetAlienCharacter: Invalid AlienController"));
		return nullptr;
	}

	return AlienController;
}

APawn* Utility::GetAlienPawn(UBehaviorTreeComponent& OwnerComponent)
{
	AAlienAIController* const AlienController = Cast<AAlienAIController>(OwnerComponent.GetAIOwner());
	if (!IsValid(AlienController))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetAlienCharacter: Invalid AlienController"));
		return nullptr;
	}

	APawn* const AlienPawn = AlienController->GetPawn();
	if (!IsValid(AlienPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetAlienCharacter: Invalid AlienPawn"));
		return nullptr;
	}

	return AlienPawn;
}

UNavigationSystemV1* Utility::GetNavigationSystem(UObject* Object)
{
	UWorld* World = Object->GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetNavigationSystem: Invalid World"));
		return nullptr;
	}

	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(World);
	if (!IsValid(NavigationSystem))
	{
		UE_LOG(LogTemp, Error, TEXT("Utility::GetNavigationSystem: Invalid NavigationSystem"));
		return nullptr;
	}

	return NavigationSystem;
}

