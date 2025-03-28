// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FunctionInvokeData.generated.h"

USTRUCT(BlueprintType)
struct FFunctionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "FunctionName"))
	FName FuncName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "FunctionClass"))
	TObjectPtr<UClass> FuncClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "FunctionType"))
	FName FuncType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "FunctionOrder"))
	int32 FuncOrder;

public:
	FFunctionData()
		: FuncName(NAME_None)
		, FuncClass(nullptr)
		, FuncType(NAME_None)
		, FuncOrder(0)
	{}

	FFunctionData(FName InFuncName, UClass* InFuncClass)
		: FuncName(InFuncName)
		, FuncClass(InFuncClass)
		, FuncType(NAME_None)
		, FuncOrder(0)
	{}

	bool IsDataValid()
	{
		return IsValid(FuncClass) && FuncName.IsNone();
	}
};

/**
 * Function Invoke를 위한 기본 클래스.
 */
UCLASS()
class VIRTUALTRACKER_API UFunctionInvokeData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFunctionInvokeData();

public:
	static UFunctionInvokeData* GetDataPtr();

	void AddActionFunction(UClass* ClassName, FString FunctionName);
	void AddSliderFunction(UClass* ClassName, FString FunctionName);
	void AddColorFunction(UClass* ClassName, FString FunctionName);
	void AddBooleanFunction(UClass* ClassName, FString FunctionName);
	void AddStringFunction(UClass* ClassName, FString FunctionName);
	void AddIntFunction(UClass* ClassName, FString FunctionName);
	void AddTextureFunction(UClass* ClassName, FString FunctionName);
	void AddNameFunction(UClass* ClassName, FString FunctionName);
	void AddVector2DFunction(UClass* ClassName, FString FunctionName);
	void AddVector3DFunction(UClass* ClassName, FString FunctionName);

	bool HasActionFunction(FString ClassName, FString FunctionName) const;
	bool HasSliderFunction(FString ClassName, FString FunctionName) const;
	bool HasColorFunction(FString ClassName, FString FunctionName) const;
	bool HasBooleanFunction(FString ClassName, FString FunctionName) const;
	bool HasStringFunction(FString ClassName, FString FunctionName)  const;
	bool HasIntFunction(FString ClassName, FString FunctionName) const;
	bool HasTextureFunction(FString ClassName, FString FunctionName) const;
	bool HasNameFunction(FString ClassName, FString FunctionName) const;
	bool HasVector2DFunction(FString ClassName, FString FunctionName) const;
	bool HasVector3DFunction(FString ClassName, FString FunctionName) const;

private:
	void CreateFunctionData();
	void ResetFunctionData();
	void RefreshFunctionData();

private:
	static TWeakObjectPtr<UFunctionInvokeData> DataPtr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> ActionFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> SliderFunctionSset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> ColorFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> BooleanFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> StringFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> IntFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> TextureFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> NameFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> Vector2DFunctionSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> Vector3DFunctionSet;


#if WITH_EDITOR
protected:
	virtual void PostInitProperties() override;
	virtual void OnCompiled();
#endif


};
