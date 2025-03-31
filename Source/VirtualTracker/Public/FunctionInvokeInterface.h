// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FunctionInvokeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFunctionInvokeInterface : public UInterface
{
	GENERATED_BODY()
};

UCLASS()
class VIRTUALTRACKER_API UFunctionInvokeInstigater : public UObject
{
	GENERATED_BODY()

public:
	void ActionFunctionInvoke(UObject* OuterObject,FName FunctionName);
	void SliderFunctionInvoke(UObject* OuterObject,FName FunctionName, float FuncParam);
	void ColorFunctionInvoke(UObject* OuterObject, FName FunctionName, FLinearColor FuncParam);
	void BooleanFunctionInvoke(UObject* OuterObject, FName FunctionName, bool FuncParam);
	void StringFunctionInvoke(UObject* OuterObject, FName FunctionName, FString FuncParam);
	void IntFunctionInvoke(UObject* OuterObject, FName FunctionName, int32 FuncParam);
	void TextureFunctionInvoke(UObject* OuterObject, FName FunctionName);
	void NameFunctionInvoke(UObject* OuterObject, FName FunctionName, FName FuncParam);
	void Vector2DFunctionInvoke(UObject* OuterObject,FName FunctionName, FVector2D FuncParam);
	void Vector3DFunctionInvoke(UObject* OuterObject,FName FunctionName, FVector FuncParam);
};

/**
 * 
 */
class VIRTUALTRACKER_API IFunctionInvokeInterface
{
	GENERATED_BODY()

public:
	void InitInvokeInterface();

public:
	UFUNCTION()
	virtual void ActionFunctionInvoke(FName FunctionName);
		
	UFUNCTION()
	virtual void SliderFunctionInvoke(FName FunctionName, float FuncParam);

	UFUNCTION()
	virtual void ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam);

	UFUNCTION()
	virtual void BooleanFunctionInvoke(FName FunctionName, bool FuncParam);

	UFUNCTION()
	virtual void StringFunctionInvoke(FName FunctionName, FString FuncParam);

	UFUNCTION()
	virtual void IntFunctionInvoke(FName FunctionName, int32 FuncParam);

	UFUNCTION()
	virtual void TextureFunctionInvoke(FName FunctionName);

	UFUNCTION()
	virtual void NameFunctionInvoke(FName FunctionName, FName FuncParam);

	UFUNCTION()
	virtual void Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam);

	UFUNCTION()
	virtual void Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam);

private:
	UFunctionInvokeInstigater* GetInstigator(UObject* OuterObject);

};
