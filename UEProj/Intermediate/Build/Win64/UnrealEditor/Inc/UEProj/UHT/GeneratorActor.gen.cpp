// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEProj/Public/GeneratorActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGeneratorActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
UEPROJ_API UClass* Z_Construct_UClass_AGeneratorActor();
UEPROJ_API UClass* Z_Construct_UClass_AGeneratorActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEProj();
// End Cross Module References

// Begin Class AGeneratorActor
void AGeneratorActor::StaticRegisterNativesAGeneratorActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGeneratorActor);
UClass* Z_Construct_UClass_AGeneratorActor_NoRegister()
{
	return AGeneratorActor::StaticClass();
}
struct Z_Construct_UClass_AGeneratorActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GeneratorActor.h" },
		{ "ModuleRelativePath", "Public/GeneratorActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGeneratorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGeneratorActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UEProj,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGeneratorActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGeneratorActor_Statics::ClassParams = {
	&AGeneratorActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGeneratorActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AGeneratorActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGeneratorActor()
{
	if (!Z_Registration_Info_UClass_AGeneratorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGeneratorActor.OuterSingleton, Z_Construct_UClass_AGeneratorActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGeneratorActor.OuterSingleton;
}
template<> UEPROJ_API UClass* StaticClass<AGeneratorActor>()
{
	return AGeneratorActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGeneratorActor);
AGeneratorActor::~AGeneratorActor() {}
// End Class AGeneratorActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projs_T_UE_Client_UEProj_Source_UEProj_Public_GeneratorActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGeneratorActor, AGeneratorActor::StaticClass, TEXT("AGeneratorActor"), &Z_Registration_Info_UClass_AGeneratorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGeneratorActor), 430686685U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projs_T_UE_Client_UEProj_Source_UEProj_Public_GeneratorActor_h_1457261936(TEXT("/Script/UEProj"),
	Z_CompiledInDeferFile_FID_Projs_T_UE_Client_UEProj_Source_UEProj_Public_GeneratorActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projs_T_UE_Client_UEProj_Source_UEProj_Public_GeneratorActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
