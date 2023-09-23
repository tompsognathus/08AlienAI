// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "AlienAIController.generated.h"

class UAISenseConfig_Sight;

UCLASS()
class ALIENAI_API AAlienAIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit AAlienAIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* const InPawn) override;

private:
	void SetupPerceptionSystem();

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);

private:
	UAISenseConfig_Sight* SightConfig;


};
