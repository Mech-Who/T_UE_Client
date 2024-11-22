// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UEProjProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef UEPROJ_UEProjProjectile_generated_h
#error "UEProjProjectile.generated.h already included, missing '#pragma once' in UEProjProjectile.h"
#endif
#define UEPROJ_UEProjProjectile_generated_h

#define FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUEProjProjectile(); \
	friend struct Z_Construct_UClass_AUEProjProjectile_Statics; \
public: \
	DECLARE_CLASS(AUEProjProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEProj"), NO_API) \
	DECLARE_SERIALIZER(AUEProjProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AUEProjProjectile(AUEProjProjectile&&); \
	AUEProjProjectile(const AUEProjProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUEProjProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUEProjProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUEProjProjectile) \
	NO_API virtual ~AUEProjProjectile();


#define FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_12_PROLOG
#define FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEPROJ_API UClass* StaticClass<class AUEProjProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projs_T_UE_Client_UEProj_Source_UEProj_UEProjProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
