// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienAIController.h"
#include "AlienAICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAlienAIController::AAlienAIController(FObjectInitializer const& ObjectInitializer)
{

}

void AAlienAIController::OnPossess(APawn* const InPawn)
{
	Super::OnPossess(InPawn);

	AAlienAICharacter const* AlienCharacter = Cast<AAlienAICharacter>(InPawn);
	if (!IsValid(AlienCharacter))
	{
		UE_LOG(LogTemp, Error, TEXT("AAlienAIController::OnPossess(): Invalid AlienCharacter"));
		return;
	}

	UBehaviorTree* const BehaviorTree = AlienCharacter->GetBehaviorTree();
	if (!BehaviorTree)
	{
		UE_LOG(LogTemp, Error, TEXT("AAlienAIController::OnPossess(): Invalid BehaviorTree"));
		return;
	}

	UBlackboardComponent* BlackboardComponent;
	UseBlackboard(BehaviorTree->BlackboardAsset, BlackboardComponent);
	Blackboard = BlackboardComponent;
	RunBehaviorTree(BehaviorTree);

}

