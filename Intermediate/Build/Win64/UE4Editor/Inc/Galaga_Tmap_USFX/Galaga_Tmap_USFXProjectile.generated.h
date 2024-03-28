// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GALAGA_TMAP_USFX_Galaga_Tmap_USFXProjectile_generated_h
#error "Galaga_Tmap_USFXProjectile.generated.h already included, missing '#pragma once' in Galaga_Tmap_USFXProjectile.h"
#endif
#define GALAGA_TMAP_USFX_Galaga_Tmap_USFXProjectile_generated_h

#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_SPARSE_DATA
#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGalaga_Tmap_USFXProjectile(); \
	friend struct Z_Construct_UClass_AGalaga_Tmap_USFXProjectile_Statics; \
public: \
	DECLARE_CLASS(AGalaga_Tmap_USFXProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_Tmap_USFX"), NO_API) \
	DECLARE_SERIALIZER(AGalaga_Tmap_USFXProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGalaga_Tmap_USFXProjectile(); \
	friend struct Z_Construct_UClass_AGalaga_Tmap_USFXProjectile_Statics; \
public: \
	DECLARE_CLASS(AGalaga_Tmap_USFXProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Galaga_Tmap_USFX"), NO_API) \
	DECLARE_SERIALIZER(AGalaga_Tmap_USFXProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGalaga_Tmap_USFXProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGalaga_Tmap_USFXProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGalaga_Tmap_USFXProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGalaga_Tmap_USFXProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGalaga_Tmap_USFXProjectile(AGalaga_Tmap_USFXProjectile&&); \
	NO_API AGalaga_Tmap_USFXProjectile(const AGalaga_Tmap_USFXProjectile&); \
public:


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGalaga_Tmap_USFXProjectile(AGalaga_Tmap_USFXProjectile&&); \
	NO_API AGalaga_Tmap_USFXProjectile(const AGalaga_Tmap_USFXProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGalaga_Tmap_USFXProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGalaga_Tmap_USFXProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGalaga_Tmap_USFXProjectile)


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(AGalaga_Tmap_USFXProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AGalaga_Tmap_USFXProjectile, ProjectileMovement); }


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_12_PROLOG
#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_SPARSE_DATA \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_RPC_WRAPPERS \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_INCLASS \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_SPARSE_DATA \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_INCLASS_NO_PURE_DECLS \
	Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GALAGA_TMAP_USFX_API UClass* StaticClass<class AGalaga_Tmap_USFXProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Galaga_Tmap_USFX_Source_Galaga_Tmap_USFX_Galaga_Tmap_USFXProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
