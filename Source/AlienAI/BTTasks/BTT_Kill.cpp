// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Kill.h"


UBTT_Kill::UBTT_Kill(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Kill");
}

EBTNodeResult::Type UBTT_Kill::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{


	return EBTNodeResult::Type();
}
