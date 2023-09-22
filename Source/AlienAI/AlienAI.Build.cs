// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AlienAI : ModuleRules
{
	public AlienAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "AIModule", "GameplayTasks", "NavigationSystem" });
	}
}
