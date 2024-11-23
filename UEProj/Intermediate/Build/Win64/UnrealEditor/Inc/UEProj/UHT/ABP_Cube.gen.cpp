// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEProj/ABP_Cube.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeABP_Cube() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UEPROJ_API UClass* Z_Construct_UClass_AABP_Cube();
UEPROJ_API UClass* Z_Construct_UClass_AABP_Cube_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEProj();
// End Cross Module References

// Begin Class AABP_Cube Function OnHit
struct Z_Construct_UFunction_AABP_Cube_OnHit_Statics
{
	struct ABP_Cube_eventOnHit_Parms
	{
		UPrimitiveComponent* HitComp;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		FVector NormalImpulse;
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// process when hit\n" },
#endif
		{ "ModuleRelativePath", "ABP_Cube.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "process when hit" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABP_Cube_eventOnHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitComp_MetaData), NewProp_HitComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABP_Cube_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABP_Cube_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABP_Cube_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABP_Cube_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AABP_Cube_OnHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_HitComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_NormalImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AABP_Cube_OnHit_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AABP_Cube_OnHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AABP_Cube_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AABP_Cube, nullptr, "OnHit", nullptr, nullptr, Z_Construct_UFunction_AABP_Cube_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AABP_Cube_OnHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_AABP_Cube_OnHit_Statics::ABP_Cube_eventOnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AABP_Cube_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AABP_Cube_OnHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AABP_Cube_OnHit_Statics::ABP_Cube_eventOnHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AABP_Cube_OnHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AABP_Cube_OnHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AABP_Cube::execOnHit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
	P_NATIVE_END;
}
// End Class AABP_Cube Function OnHit

// Begin Class AABP_Cube
void AABP_Cube::StaticRegisterNativesAABP_Cube()
{
	UClass* Class = AABP_Cube::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnHit", &AABP_Cube::execOnHit },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AABP_Cube);
UClass* Z_Construct_UClass_AABP_Cube_NoRegister()
{
	return AABP_Cube::StaticClass();
}
struct Z_Construct_UClass_AABP_Cube_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ABP_Cube.h" },
		{ "ModuleRelativePath", "ABP_Cube.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsImportant_MetaData[] = {
		{ "Category", "Cube" },
		{ "ModuleRelativePath", "ABP_Cube.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScoreValue_MetaData[] = {
		{ "Category", "Cube" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current score\n" },
#endif
		{ "ModuleRelativePath", "ABP_Cube.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current score" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleFactor_MetaData[] = {
		{ "Category", "Cube" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current scale factor\n" },
#endif
		{ "ModuleRelativePath", "ABP_Cube.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current scale factor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinScale_MetaData[] = {
		{ "Category", "Cube" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// minimal scale value, destroy this actor when ScaleFactor < MinScale\n" },
#endif
		{ "ModuleRelativePath", "ABP_Cube.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "minimal scale value, destroy this actor when ScaleFactor < MinScale" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticCubeMesh_MetaData[] = {
		{ "Category", "Cube" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cube mesh\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ABP_Cube.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cube mesh" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_IsImportant_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsImportant;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScoreValue;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ScaleFactor;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_MinScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticCubeMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AABP_Cube_OnHit, "OnHit" }, // 1826969874
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AABP_Cube>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AABP_Cube_Statics::NewProp_IsImportant_SetBit(void* Obj)
{
	((AABP_Cube*)Obj)->IsImportant = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AABP_Cube_Statics::NewProp_IsImportant = { "IsImportant", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AABP_Cube), &Z_Construct_UClass_AABP_Cube_Statics::NewProp_IsImportant_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsImportant_MetaData), NewProp_IsImportant_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AABP_Cube_Statics::NewProp_ScoreValue = { "ScoreValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABP_Cube, ScoreValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScoreValue_MetaData), NewProp_ScoreValue_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AABP_Cube_Statics::NewProp_ScaleFactor = { "ScaleFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABP_Cube, ScaleFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleFactor_MetaData), NewProp_ScaleFactor_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AABP_Cube_Statics::NewProp_MinScale = { "MinScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABP_Cube, MinScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinScale_MetaData), NewProp_MinScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AABP_Cube_Statics::NewProp_StaticCubeMesh = { "StaticCubeMesh", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AABP_Cube, StaticCubeMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticCubeMesh_MetaData), NewProp_StaticCubeMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AABP_Cube_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABP_Cube_Statics::NewProp_IsImportant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABP_Cube_Statics::NewProp_ScoreValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABP_Cube_Statics::NewProp_ScaleFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABP_Cube_Statics::NewProp_MinScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AABP_Cube_Statics::NewProp_StaticCubeMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABP_Cube_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AABP_Cube_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UEProj,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AABP_Cube_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AABP_Cube_Statics::ClassParams = {
	&AABP_Cube::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AABP_Cube_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AABP_Cube_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AABP_Cube_Statics::Class_MetaDataParams), Z_Construct_UClass_AABP_Cube_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AABP_Cube()
{
	if (!Z_Registration_Info_UClass_AABP_Cube.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AABP_Cube.OuterSingleton, Z_Construct_UClass_AABP_Cube_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AABP_Cube.OuterSingleton;
}
template<> UEPROJ_API UClass* StaticClass<AABP_Cube>()
{
	return AABP_Cube::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AABP_Cube);
AABP_Cube::~AABP_Cube() {}
// End Class AABP_Cube

// Begin Registration
struct Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AABP_Cube, AABP_Cube::StaticClass, TEXT("AABP_Cube"), &Z_Registration_Info_UClass_AABP_Cube, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AABP_Cube), 508264127U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_330309231(TEXT("/Script/UEProj"),
	Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
