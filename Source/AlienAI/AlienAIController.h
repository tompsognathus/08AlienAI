// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AlienAIController.generated.h"

/**
 * 
 */
UCLASS()
class ALIENAI_API AAlienAIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit AAlienAIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* const InPawn) override;



};
