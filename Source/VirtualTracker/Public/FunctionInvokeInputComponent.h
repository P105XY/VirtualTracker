// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "EnhancedPlayerInput.h"
#include "FunctionInvokeInputComponent.generated.h"

class UFunctionInvokeData;
class UEnhancedPlayerInput;

extern VIRTUALTRACKER_API const FName ActionFunction_META;
extern VIRTUALTRACKER_API const FName SliderFunction_META;
extern VIRTUALTRACKER_API const FName ColorFunction_META;
extern VIRTUALTRACKER_API const FName BooleanFunction_META;
extern VIRTUALTRACKER_API const FName StringFunction_META;
extern VIRTUALTRACKER_API const FName IntFunction_META;
extern VIRTUALTRACKER_API const FName TextureFunction_META;
extern VIRTUALTRACKER_API const FName NameFunction_META;
extern VIRTUALTRACKER_API const FName Vector2DFunction_META;
extern VIRTUALTRACKER_API const FName Vector3DFunction_META;

UENUM(BlueprintType)
enum class EFunctionType : uint8
{
	NONE UMETA(Hidden),
	Action,
	Slider,
	Color,
	Boolean,
	String,
	Int,
	Texture,
	Name,
	Vector2D,
	Vector3D
};

USTRUCT(BlueprintType)
struct FActionFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ActionFunctionName;
};

USTRUCT(BlueprintType)
struct FSliderFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SliderFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SliderFunctionParam;
};

USTRUCT(BlueprintType)
struct FColorFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ColorFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor ColorFunctionParam;
};

USTRUCT(BlueprintType)
struct FBooleanFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName BooleanFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BooleanFunctionParam;
};

USTRUCT(BlueprintType)
struct FStringFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName StringFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StringFunctionParam;
};

USTRUCT(BlueprintType)
struct FIntFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName IntFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntFunctionParam;
};

USTRUCT(BlueprintType)
struct FTextureFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TextureFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> TextureFunctionParam;
};

USTRUCT(BlueprintType)
struct FNameFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FNameFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FNameFunctionParam;
};

USTRUCT(BlueprintType)
struct FVector2DFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Vector2DFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Vector2DFunctionParam;
};

USTRUCT(BlueprintType)
struct FVector3DFunctionInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Vector3DFunctionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Vector3DFunctionParam;
};

USTRUCT(BlueprintType)
struct FunctionInfoCollection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFunctionType EFunctionTypeMeta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FActionFunctionInfo ActionInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FSliderFunctionInfo SliderInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FColorFunctionInfo ColorInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FBooleanFunctionInfo BooleanInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FStringFunctionInfo StringInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FIntFunctionInfo IntInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FTextureFunctionInfo TextureInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FNameFunctionInfo NameInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FVector2DFunctionInfo Vector2DInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShowOnlyInnerProperties))
	FVector3DFunctionInfo Vector3DInfo;
};

USTRUCT(BlueprintType)
struct FFunctionInvokeInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UClass* FunctionOwner;

	UPROPERTY(Transient)
	UFunction* InvokeFunction;

public:
	FFunctionInvokeInfo()
	{
		FunctionOwner = nullptr;
		InvokeFunction = nullptr;
	}

	FFunctionInvokeInfo(UClass* InFunctionOwner, UFunction* InInvokeFunction)
	{
		FunctionOwner = InFunctionOwner;
		InvokeFunction = InInvokeFunction;
	}

	bool IsValidData() const
	{
		return IsValid(FunctionOwner) && IsValid(InvokeFunction);
	}
};

USTRUCT(BlueprintType)
struct FFunctionInvokeObjectData
{
	GENERATED_BODY()

public:
	TObjectPtr<UObject> InvokeObject;
	TObjectPtr<UFunction> InvokeFunction;

	FFunctionInvokeObjectData()
		: InvokeObject(nullptr)
		, InvokeFunction(nullptr)
	{}

	FFunctionInvokeObjectData(UObject* InUObject, UFunction* InInvokeFunction)
		: InvokeObject(InUObject)
		, InvokeFunction(InInvokeFunction)
	{}

	bool IsInvokeValid() const
	{
		return IsValid(InvokeObject) && IsValid(InvokeFunction);
	}

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionInvoke, FName, ActionFunctionName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSliderInvoke, FName, SliderFunctionName, float, SliderValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorInvoke, FName, ColorFunctionName, FLinearColor, ColorValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBooleanInvoke, FName, BooleanFunctionName, bool, BooleanValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStringInvoke, FName, StringFunctionName, const FString&, StringValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIntInvoke, FName, IntFunctionName, int32, IntValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTextureInvoke, FName, TextureFunctionName, TSoftObjectPtr<UTexture>, TextureValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNameInvoke, FName, FuncName, FName, NameValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVector3DInvoke, FName, VectorFunctionName, FVector, VectorValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVector2DInvoke, FName, Vector2DFunctionName, FVector2D, Vector2DValue);

UCLASS(Within = PlayerController, config = Input, transient)
class UFunctionInvokeInputComponent : public UEnhancedPlayerInput
{
	GENERATED_BODY()

public:
	void InitInvokeManager(UObject* InvokeObject,
		EFieldIteratorFlags::SuperClassFlags SuperClassFlag = EFieldIteratorFlags::IncludeSuper,
		EFieldIteratorFlags::DeprecatedPropertyFlags DeprecatedFieldFlag = EFieldIteratorFlags::ExcludeDeprecated,
		EFieldIteratorFlags::InterfaceClassFlags InterfaceFieldFlag = EFieldIteratorFlags::ExcludeInterfaces);

public:
	static UFunctionInvokeInputComponent* GetInputComponent(APlayerController* PlayerController);

public:
	void ActionFunctionInvoke(FName FunctionName);
	void SliderFunctionInvoke(FName FunctionName, float FuncParam);
	void ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam);
	void BooleanFunctionInvoke(FName FunctionName, bool FuncParam);
	void StringFunctionInvoke(FName FunctionName, FString FuncParam);
	void IntFunctionInvoke(FName FunctionName, int32 FuncParam);
	void TextureFunctionInvoke(FName FunctionName);
	void NameFunctionInvoke(FName FunctionName, FName FuncParam);
	void Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam);
	void Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam);

public:
	UPROPERTY()
	FOnActionInvoke OnActionInvoke;

	UPROPERTY()
	FOnSliderInvoke OnSliderInvoke;

	UPROPERTY()
	FOnColorInvoke OnColorInvoke;

	UPROPERTY()
	FOnBooleanInvoke OnBooleanInvoke;

	UPROPERTY()
	FOnStringInvoke OnStringInvoke;

	UPROPERTY()
	FOnIntInvoke OnIntInvoke;

	UPROPERTY()
	FOnTextureInvoke OnTextureInvoke;

	UPROPERTY()
	FOnNameInvoke OnNameInvoke;

	UPROPERTY()
	FOnVector3DInvoke OnVector3DInvoke;

	UPROPERTY()
	FOnVector2DInvoke OnVector2DInvoke;


private:
	UPROPERTY(Transient)
	TObjectPtr<UFunctionInvokeData> FuncData;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> ActionFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> ColorFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> SliderFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> BooleanFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> IntFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> TextureFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> StringFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> NameFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> Vector2DFunctionInvokeArray;

	UPROPERTY(Transient)
	TArray<FFunctionInvokeObjectData> Vector3DFunctionInvokeArray;

};