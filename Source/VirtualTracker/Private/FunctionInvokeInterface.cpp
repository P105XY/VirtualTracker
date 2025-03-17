// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionInvokeInterface.h"

// Add default functionality here for any IFunctionInvokeInterface functions that are not pure virtual.


void UFunctionInvokeInstigater::ActionFunctionInvoke(FName FunctionName)
{
}

void UFunctionInvokeInstigater::SliderFunctionInvoke(FName FunctionName, float FuncParam)
{
}

void UFunctionInvokeInstigater::ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam)
{
}

void UFunctionInvokeInstigater::BooleanFunctionInvoke(FName FunctionName, bool FuncParam)
{
}

void UFunctionInvokeInstigater::StringFunctionInvoke(FName FunctionName, FString FuncParam)
{
}

void UFunctionInvokeInstigater::IntFunctionInvoke(FName FunctionName, int32 FuncParam)
{
}

void UFunctionInvokeInstigater::TextureFunctionInvoke(FName FunctionName)
{
}

void UFunctionInvokeInstigater::NameFunctionInvoke(FName FunctionName, FName FuncParam)
{
}

void UFunctionInvokeInstigater::Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam)
{
}

void UFunctionInvokeInstigater::Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam)
{
}


void IFunctionInvokeInterface::ActionFunctionInvoke(FName FunctionName)
{
}

void IFunctionInvokeInterface::SliderFunctionInvoke(FName FunctionName, float FuncParam)
{
}

void IFunctionInvokeInterface::ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam)
{
}

void IFunctionInvokeInterface::BooleanFunctionInvoke(FName FunctionName, bool FuncParam)
{
}

void IFunctionInvokeInterface::StringFunctionInvoke(FName FunctionName, FString FuncParam)
{
}

void IFunctionInvokeInterface::IntFunctionInvoke(FName FunctionName, int32 FuncParam)
{
}

void IFunctionInvokeInterface::TextureFunctionInvoke(FName FunctionName)
{
}

void IFunctionInvokeInterface::NameFunctionInvoke(FName FunctionName, FName FuncParam)
{
}

void IFunctionInvokeInterface::Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam)
{
}

void IFunctionInvokeInterface::Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam)
{
}

UFunctionInvokeInstigater* IFunctionInvokeInterface::GetInstigator(UObject* OuterObject)
{
	if (!IsValid(OuterObject))
	{
		return nullptr;
	}

	UFunctionInvokeInstigater* ObjectInstigator = (UFunctionInvokeInstigater*)StaticFindObjectSafe(
		UFunctionInvokeInstigater::StaticClass(),
		OuterObject,
		*UFunctionInvokeInstigater::StaticClass()->GetName(),
		true);

	return nullptr;
}
