// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_FindRandomLocation.h"
#include "../AlienAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTT_FindRandomLocation::UBTT_FindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Random NavMesh Location";

}

EBTNodeResult::Type UBTT_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	AAlienAIController* const AlienController = Cast<AAlienAIController>(OwnerComponent.GetAIOwner());
	if (!IsValid(AlienController))
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_FindRandomLocation::ExecuteTask(): Invalid AlienController"));
		return EBTNodeResult::Failed;
	}
	
	APawn* AlienPawn = AlienController->GetPawn();
	if (!IsValid(AlienPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_FindRandomLocation::ExecuteTask(): Invalid AlienPawn"));
		return EBTNodeResult::Failed;
	}

	FVector const CurrentActorLocation = AlienPawn->GetActorLocation();
	
	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!IsValid(NavigationSystem))
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_FindRandomLocation::ExecuteTask(): Invalid NavigationSystem"));
		return EBTNodeResult::Failed;
	}

	FNavLocation RandomLocation;
	if (!NavigationSystem->GetRandomPointInNavigableRadius(CurrentActorLocation, SearchRadius, RandomLocation))
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_FindRandomLocation::ExecuteTask(): Failed to find random location"));
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* BlackboardComponent = OwnerComponent.GetBlackboardComponent();
	if (!BlackboardComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("UBTT_FindRandomLocation::ExecuteTask(): Invalid BlackboardComponent"));
		return EBTNodeResult::Failed;
	}

	BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), RandomLocation.Location);

	FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
