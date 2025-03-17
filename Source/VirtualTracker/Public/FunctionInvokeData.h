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

	TArray<FFunctionData> GetActionFunction() const;
	TArray<FFunctionData> GetSliderFunction() const;
	TArray<FFunctionData> GetColorFunction() const;
	TArray<FFunctionData> GetBooleanFunction() const;
	TArray<FFunctionData> GetStringFunction() const;
	TArray<FFunctionData> GetIntFunction() const;
	TArray<FFunctionData> GetTextureFunction() const;
	TArray<FFunctionData> GetNameFunction() const;
	TArray<FFunctionData> GetVector2DFunction() const;
	TArray<FFunctionData> GetVector3DFunction() const;

private:
	void CreateFunctionData();
	void ResetFunctionData();

private:
	static TWeakObjectPtr<UFunctionInvokeData> DataPtr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> ActionFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> SliderFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> ColorFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> BooleanFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> StringFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> IntFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> TextureFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> NameFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> Vector2DFuncList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<FName, FFunctionData> Vector3DFuncList;

#if WITH_EDITOR
protected:
	virtual void PostInitProperties() override;
	virtual void OnCompiled();
#endif


};
