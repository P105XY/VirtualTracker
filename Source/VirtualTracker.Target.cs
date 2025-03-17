// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VirtualTrackerTarget : TargetRules
{
	public VirtualTrackerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
        ExtraModuleNames.AddRange(new string[] { "VirtualTracker", "VirtualCustomizer" });
        bUseAdaptiveUnityBuild = false;
        bAdaptiveUnityDisablesPCH = true;
    }
}
