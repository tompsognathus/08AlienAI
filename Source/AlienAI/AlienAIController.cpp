// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienAIController.h"
#include "AlienAICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"


AAlienAIController::AAlienAIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
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

void AAlienAIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (!IsValid(SightConfig))
	{
		UE_LOG(LogTemp, Error, TEXT("AAlienAIController::SetupPerceptionSystem(): Invalid SightConfig"));
		return;
	}

	UAIPerceptionComponent* const AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
	if (!IsValid(AIPerceptionComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("AAlienAIController::SetupPerceptionSystem(): Invalid PerceptionComponent"));
		return;
	}

	SetPerceptionComponent(*AIPerceptionComponent);
	SightConfig->SightRadius = 500.f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
	SightConfig->PeripheralVisionAngleDegrees = 60.f;
	SightConfig->SetMaxAge(5.f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComponent->SetDominantSense(*SightConfig->GetSenseImplementation());
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AAlienAIController::OnTargetDetected);
	PerceptionComponent->ConfigureSense(*SightConfig);
}

void AAlienAIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	UE_LOG(LogTemp, Error, TEXT("AAlienAIController::OnTargetDetected()"));
}

