// Fill out your copyright notice in the Description page of Project Settings.

#include "FunctionInvokeData.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "FunctionInvokeInputComponent.h"
#include "UObject/SavePackage.h"

TWeakObjectPtr<UFunctionInvokeData> UFunctionInvokeData::DataPtr;

UFunctionInvokeData::UFunctionInvokeData()
{
	FCoreDelegates::OnPostEngineInit.AddLambda(
		[this]()
		{
			CreateFunctionData();
		}
	);
}

UFunctionInvokeData* UFunctionInvokeData::GetDataPtr()
{
	if (!DataPtr.IsValid())
	{
		FString DataPath = TEXT("/Game/FunctionInvoke/BP_FuncInvoke.BP_FuncInvoke");
		DataPtr = LoadObject<UFunctionInvokeData>(GetTransientPackage(), *DataPath);
	}

	return DataPtr.Get();
}

void UFunctionInvokeData::AddActionFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddSliderFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddColorFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddBooleanFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddStringFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddIntFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddTextureFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddNameFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddVector2DFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

void UFunctionInvokeData::AddVector3DFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);

	FString FuncElemStr = FString::Printf(TEXT("%s_%s"), *ClassName->GetName(), *FunctionName);
	ActionFunctionSet.Add(FName(*FuncElemStr));
}

bool UFunctionInvokeData::HasActionFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : ActionFunctionSet)
	{
		FString CandidateClassName;
		FString CandidateFunctionName;

		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasSliderFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;


	for (const FName& CandidateFunc : SliderFunctionSset)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasColorFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;


	for (const FName& CandidateFunc : ColorFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasBooleanFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : BooleanFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasStringFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : StringFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasIntFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : IntFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasTextureFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : TextureFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasNameFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : NameFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasVector2DFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : Vector2DFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

bool UFunctionInvokeData::HasVector3DFunction(FString ClassName, FString FunctionName) const
{
	if (ClassName.IsEmpty())
	{
		return false;
	}

	if (FunctionName.IsEmpty())
	{
		return false;
	}

	bool bIsFunctionValid = false;

	for (const FName& CandidateFunc : Vector3DFunctionSet)
	{
		if (!CandidateFunc.ToString().Equals(FunctionName))
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

void UFunctionInvokeData::CreateFunctionData()
{
#if WITH_EDITOR

	UFunctionInvokeData* FunctionDataPtr = GetDataPtr();

	if (IsValid(FunctionDataPtr))
	{
		RefreshFunctionData();
		return;
	}

 	FString DataPathName = TEXT("/Game/FunctionInvoke/BP_FuncInvoke");
	UPackage* FunctionDataPac = CreatePackage(*DataPathName);

	TObjectPtr<UObject> FuncDataObject = NewObject<UFunctionInvokeData>(FunctionDataPac, UFunctionInvokeData::StaticClass(), TEXT("BP_FuncInvoke"), EObjectFlags::RF_Public | EObjectFlags::RF_Standalone);
	FAssetRegistryModule::AssetCreated(FuncDataObject);

	FString PackageName = FunctionDataPac->GetName();
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	FSavePackageArgs SavePackageArgs;
	SavePackageArgs.TopLevelFlags = RF_Public | RF_Standalone;
	SavePackageArgs.Error = GError;
	SavePackageArgs.bForceByteSwapping = false;
	SavePackageArgs.bWarnOfLongFilename = true;
	SavePackageArgs.SaveFlags = SAVE_NoError;

	UPackage::SavePackage(FunctionDataPac, nullptr, *PackageFileName, SavePackageArgs);
	RefreshFunctionData();
#endif
}

void UFunctionInvokeData::ResetFunctionData()
{
}

void UFunctionInvokeData::RefreshFunctionData()
{
	UFunctionInvokeData* InvokeData = GetDataPtr();
	if (!IsValid(InvokeData))
	{
		return;
	}

	for (UClass* CandidateInvokeClass : TObjectRange<UClass>())
	{
		if (!CandidateInvokeClass->IsNative())
		{
			continue;
		}

		FString ClassName = CandidateInvokeClass->GetName();
		if (ClassName.IsEmpty())
		{
			continue;
		}

		for (UFunction* CandidateInvokeFunction : TFieldRange<UFunction>(CandidateInvokeClass, EFieldIterationFlags::IncludeDeprecated))
		{
			if (!IsValid(CandidateInvokeFunction))
			{
				continue;
			}

			FString CandidateFunctionName = CandidateInvokeFunction->GetName();
			if (CandidateFunctionName.IsEmpty())
			{
				continue;
			}

			FFunctionData ActionInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(ActionFunction_META))
			{
				AddActionFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData SliderInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(SliderFunction_META))
			{
				AddSliderFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData ColorInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(ColorFunction_META))
			{
				AddColorFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData BooleanInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(BooleanFunction_META))
			{
				AddBooleanFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData StringInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(StringFunction_META))
			{
				AddStringFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData IntInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(IntFunction_META))
			{
				AddIntFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData TextureInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(TextureFunction_META))
			{
				AddTextureFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData NameInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(NameFunction_META))
			{
				AddNameFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData Vector2DInvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(Vector2DFunction_META))
			{
				AddVector2DFunction(CandidateInvokeClass, CandidateFunctionName);
			}
			FFunctionData Vector3InvokeFunctionData = FFunctionData(CandidateInvokeFunction->GetFName(), CandidateInvokeClass);
			if (CandidateInvokeFunction->HasMetaData(Vector3DFunction_META))
			{
				AddVector3DFunction(CandidateInvokeClass, CandidateFunctionName);
			}
		}
	}
}

void UFunctionInvokeData::PostInitProperties()
{
	Super::PostInitProperties();
	UE_LOG(LogTemp, Log, TEXT("PostInitProperties"));
}

void UFunctionInvokeData::OnCompiled()
{
	UE_LOG(LogTemp, Log, TEXT("On Compiled"));
}