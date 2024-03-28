// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_Tmap_USFX/Galaga_Tmap_USFXGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGalaga_Tmap_USFXGameMode() {}
// Cross Module References
	GALAGA_TMAP_USFX_API UClass* Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_NoRegister();
	GALAGA_TMAP_USFX_API UClass* Z_Construct_UClass_AGalaga_Tmap_USFXGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Galaga_Tmap_USFX();
// End Cross Module References
	void AGalaga_Tmap_USFXGameMode::StaticRegisterNativesAGalaga_Tmap_USFXGameMode()
	{
	}
	UClass* Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_NoRegister()
	{
		return AGalaga_Tmap_USFXGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_Tmap_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Galaga_Tmap_USFXGameMode.h" },
		{ "ModuleRelativePath", "Galaga_Tmap_USFXGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGalaga_Tmap_USFXGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::ClassParams = {
		&AGalaga_Tmap_USFXGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGalaga_Tmap_USFXGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGalaga_Tmap_USFXGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGalaga_Tmap_USFXGameMode, 2706529011);
	template<> GALAGA_TMAP_USFX_API UClass* StaticClass<AGalaga_Tmap_USFXGameMode>()
	{
		return AGalaga_Tmap_USFXGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGalaga_Tmap_USFXGameMode(Z_Construct_UClass_AGalaga_Tmap_USFXGameMode, &AGalaga_Tmap_USFXGameMode::StaticClass, TEXT("/Script/Galaga_Tmap_USFX"), TEXT("AGalaga_Tmap_USFXGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGalaga_Tmap_USFXGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
