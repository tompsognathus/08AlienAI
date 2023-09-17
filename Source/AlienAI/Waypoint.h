// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Waypoint.generated.h"

UCLASS()
class ALIENAI_API AWaypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	AWaypoint();

protected:
	virtual void BeginPlay() override;


};
