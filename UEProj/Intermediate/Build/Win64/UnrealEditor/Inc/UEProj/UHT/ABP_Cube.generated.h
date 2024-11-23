// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ABP_Cube.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef UEPROJ_ABP_Cube_generated_h
#error "ABP_Cube.generated.h already included, missing '#pragma once' in ABP_Cube.h"
#endif
#define UEPROJ_ABP_Cube_generated_h

#define FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAABP_Cube(); \
	friend struct Z_Construct_UClass_AABP_Cube_Statics; \
public: \
	DECLARE_CLASS(AABP_Cube, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEProj"), NO_API) \
	DECLARE_SERIALIZER(AABP_Cube)


#define FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AABP_Cube(AABP_Cube&&); \
	AABP_Cube(const AABP_Cube&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AABP_Cube); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AABP_Cube); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AABP_Cube) \
	NO_API virtual ~AABP_Cube();


#define FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_9_PROLOG
#define FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_INCLASS_NO_PURE_DECLS \
	FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEPROJ_API UClass* StaticClass<class AABP_Cube>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GProjs_T_UE_Client_UEProj_Source_UEProj_ABP_Cube_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
