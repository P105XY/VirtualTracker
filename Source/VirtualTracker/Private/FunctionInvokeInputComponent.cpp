// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionInvokeInputComponent.h"
#include "FunctionInvokeData.h"

const FName ActionFunction_META = TEXT("ActionFunction");
const FName SliderFunction_META = TEXT("SliderFunction");
const FName ColorFunction_META = TEXT("ColorFunction");
const FName BooleanFunction_META = TEXT("BooleanFunction");
const FName StringFunction_META = TEXT("StringFunction");
const FName IntFunction_META = TEXT("IntFunction");
const FName TextureFunction_META = TEXT("TextureFunction");
const FName NameFunction_META = TEXT("FNameFunction");
const FName Vector2DFunction_META = TEXT("Vector2DFunction");
const FName Vector3DFunction_META = TEXT("Vector3DFunction");

//해당 함수에서는 함수 찾기 및 리스트에 저장만 진행.
//실제 함수의 Invoke는 아래 함수에서 진행하도록 한다.
void UFunctionInvokeInputComponent::InitInvokeManager(UObject* InvokeObject, 
	EFieldIteratorFlags::SuperClassFlags SuperClassFlag, 
	EFieldIteratorFlags::DeprecatedPropertyFlags DeprecatedFieldFlag, 
	EFieldIteratorFlags::InterfaceClassFlags InterfaceFieldFlag)
{
	UFunctionInvokeData* TempFuncData = UFunctionInvokeData::GetDataPtr();
	FuncData = TempFuncData;

	UClass* InvokeClass = InvokeObject->GetClass();
	for (UFunction* Function : TFieldRange<UFunction>(InvokeClass, SuperClassFlag, DeprecatedFieldFlag, InterfaceFieldFlag))
	{
		if (!IsValid(Function))
		{
			continue;
		}

		FString FuncNameStr = *Function->GetName();
		if (FuncNameStr.IsEmpty())
		{
			continue;
		}

		FNativeFuncPtr NativeFuncPtr = Function->GetNativeFunc();
		if (NativeFuncPtr == nullptr)
		{
			continue;
		}

		FFunctionInvokeObjectData FuncInvokeData(InvokeObject, Function);

		if (FuncData->HasActionFunction(InvokeClass->GetName(), FuncNameStr))
		{
			ActionFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasSliderFunction(InvokeClass->GetName(), FuncNameStr))
		{
			SliderFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasColorFunction(InvokeClass->GetName(), FuncNameStr))
		{
			ColorFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasBooleanFunction(InvokeClass->GetName(), FuncNameStr))
		{
			BooleanFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasStringFunction(InvokeClass->GetName(), FuncNameStr))
		{
			StringFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasIntFunction(InvokeClass->GetName(), FuncNameStr))
		{
			IntFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasTextureFunction(InvokeClass->GetName(), FuncNameStr))
		{
			TextureFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasNameFunction(InvokeClass->GetName(), FuncNameStr))
		{
			NameFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasVector2DFunction(InvokeClass->GetName(), FuncNameStr))
		{
			Vector2DFunctionInvokeArray.Add(FuncInvokeData);
		}
		else if (FuncData->HasVector3DFunction(InvokeClass->GetName(), FuncNameStr))
		{
			Vector3DFunctionInvokeArray.Add(FuncInvokeData);
		}
	}
}

UFunctionInvokeInputComponent* UFunctionInvokeInputComponent::GetInputComponent(APlayerController* PlayerController)
{
	if (!PlayerController)
	{
		return nullptr;
	}

	return Cast<UFunctionInvokeInputComponent>(PlayerController->PlayerInput);
}

void UFunctionInvokeInputComponent::ActionFunctionInvoke(FName FunctionName)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : ActionFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, nullptr);
	}
}

void UFunctionInvokeInputComponent::SliderFunctionInvoke(FName FunctionName, float FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : SliderFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : ColorFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::BooleanFunctionInvoke(FName FunctionName, bool FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : BooleanFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::StringFunctionInvoke(FName FunctionName, FString FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : StringFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::IntFunctionInvoke(FName FunctionName, int32 FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : IntFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::TextureFunctionInvoke(FName FunctionName)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : TextureFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, nullptr);
	}
}

void UFunctionInvokeInputComponent::NameFunctionInvoke(FName FunctionName, FName FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : NameFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : Vector2DFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}

void UFunctionInvokeInputComponent::Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	for (FFunctionInvokeObjectData InvokeObj : Vector3DFunctionInvokeArray)
	{
		if (!InvokeObj.IsInvokeValid())
		{
			continue;
		}

		UObject* FunctionInvokeOwner = InvokeObj.InvokeObject;
		if (!IsValid(FunctionInvokeOwner))
		{
			continue;
		}

		FunctionInvokeOwner->ProcessEvent(InvokeObj.InvokeFunction, &FuncParam);
	}
}
