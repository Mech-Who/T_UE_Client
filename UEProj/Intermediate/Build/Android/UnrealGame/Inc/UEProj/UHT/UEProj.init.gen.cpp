// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUEProj_init() {}
	UEPROJ_API UFunction* Z_Construct_UDelegateFunction_UEProj_OnPickUp__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UEProj;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UEProj()
	{
		if (!Z_Registration_Info_UPackage__Script_UEProj.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UEProj_OnPickUp__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UEProj",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x9034EE99,
				0xF7520DD0,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UEProj.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UEProj.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UEProj(Z_Construct_UPackage__Script_UEProj, TEXT("/Script/UEProj"), Z_Registration_Info_UPackage__Script_UEProj, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x9034EE99, 0xF7520DD0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
