using UnrealBuildTool;

public class SimpleShooter : ModuleRules
{
	public SimpleShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayTasks", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
