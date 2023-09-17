// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Path.generated.h"

class AWaypoint;

UCLASS()
class ALIENAI_API APath : public AActor
{
	GENERATED_BODY()
	
public:	
	APath();

	TArray<AWaypoint*> GetPath() const { return Waypoints; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	TArray<AWaypoint*> Waypoints;
};
