// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEProj/UEProjGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUEProjGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UEPROJ_API UClass* Z_Construct_UClass_AUEProjGameMode();
UEPROJ_API UClass* Z_Construct_UClass_AUEProjGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEProj();
// End Cross Module References

// Begin Class AUEProjGameMode
void AUEProjGameMode::StaticRegisterNativesAUEProjGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUEProjGameMode);
UClass* Z_Construct_UClass_AUEProjGameMode_NoRegister()
{
	return AUEProjGameMode::StaticClass();
}
struct Z_Construct_UClass_AUEProjGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UEProjGameMode.h" },
		{ "ModuleRelativePath", "UEProjGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUEProjGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AUEProjGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_UEProj,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUEProjGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUEProjGameMode_Statics::ClassParams = {
	&AUEProjGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUEProjGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUEProjGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AUEProjGameMode()
{
	if (!Z_Registration_Info_UClass_AUEProjGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUEProjGameMode.OuterSingleton, Z_Construct_UClass_AUEProjGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUEProjGameMode.OuterSingleton;
}
template<> UEPROJ_API UClass* StaticClass<AUEProjGameMode>()
{
	return AUEProjGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AUEProjGameMode);
AUEProjGameMode::~AUEProjGameMode() {}
// End Class AUEProjGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_UEProjGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUEProjGameMode, AUEProjGameMode::StaticClass, TEXT("AUEProjGameMode"), &Z_Registration_Info_UClass_AUEProjGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUEProjGameMode), 843769626U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_UEProjGameMode_h_3471478266(TEXT("/Script/UEProj"),
	Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_UEProjGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_UEProjGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
