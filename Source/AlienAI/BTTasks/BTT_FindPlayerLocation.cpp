// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_FindPlayerLocation.h"
#include "NavigationSystem.h"
#include "../AlienAICharacter.h"
#include "../Utility.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTT_FindPlayerLocation::UBTT_FindPlayerLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UBTT_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	AAlienAICharacter* const PlayerCharacter = Utility::GetPlayerCharacter(this);
	if (!IsValid(PlayerCharacter))
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_Kill: Invalid PlayerCharacter"));
		return EBTNodeResult::Failed;
	}

	FVector const PlayerLocation = PlayerCharacter->GetActorLocation();

	if (SearchRandom)
	{
		FNavLocation RandomLocation;

		UNavigationSystemV1* NavigationSystem = Utility::GetNavigationSystem(this);
		if (!IsValid(NavigationSystem))
		{
			UE_LOG(LogTemp, Error, TEXT("UBTT_FindPlayerLocation::ExecuteTask: Invalid NavigationSystem"));
			return EBTNodeResult::Failed;
		}

		if (!NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, RandomLocation))
		{
			UE_LOG(LogTemp, Error, TEXT("UBTT_FindPlayerLocation::ExecuteTask: Failed to find random location"));
			return EBTNodeResult::Failed;
		}

		UBlackboardComponent* BlackboardComponent = OwnerComponent.GetBlackboardComponent();
		if (!BlackboardComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("UBTT_FindPlayerLocation::ExecuteTask(): Invalid BlackboardComponent"));
			return EBTNodeResult::Failed;
		}

		BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), RandomLocation.Location);
	}
	else
	{
		UBlackboardComponent* BlackboardComponent = OwnerComponent.GetBlackboardComponent();
		if (!BlackboardComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("UBTT_FindPlayerLocation::ExecuteTask(): Invalid BlackboardComponent"));
			return EBTNodeResult::Failed;
		}

		BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
	}

	FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}


