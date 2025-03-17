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
		FString DataPath = TEXT("/Engine/FunctionInvoke/BP_FuncInvoke");
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

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	ActionFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddSliderFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	SliderFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddColorFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	ColorFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddBooleanFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	BooleanFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddStringFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	StringFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddIntFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	IntFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddTextureFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	TextureFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddNameFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	NameFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddVector2DFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	Vector2DFuncList.Add(InsertElem);
}

void UFunctionInvokeData::AddVector3DFunction(UClass* ClassName, FString FunctionName)
{
	if (FunctionName.IsEmpty())
	{
		return;
	}

	FName FunctionFName = FName(*FunctionName);

	FFunctionData FuncElemData = FFunctionData(FunctionFName, ClassName);
	TTuple<FName, FFunctionData> InsertElem = TTuple<FName, FFunctionData>(FunctionFName, FuncElemData);
	Vector3DFuncList.Add(InsertElem);
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : ActionFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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


	for (const TTuple<FName, FFunctionData>& CandidateFunc : SliderFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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


	for (const TTuple<FName, FFunctionData>& CandidateFunc : ColorFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : BooleanFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : StringFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : IntFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : TextureFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : NameFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : Vector2DFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
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

	for (const TTuple<FName, FFunctionData>& CandidateFunc : Vector3DFuncList)
	{
		FFunctionData CandidateFuncData = CandidateFunc.Value;
		FName FuncFName = FName(*FunctionName);
		if (!CandidateFuncData.FuncName.IsEqual(FuncFName))
		{
			continue;
		}

		if (!CandidateFuncData.IsDataValid())
		{
			continue;
		}

		bIsFunctionValid = true;
		break;
	}

	return bIsFunctionValid;
}

TArray<FFunctionData> UFunctionInvokeData::GetActionFunction() const
{
	TArray<FFunctionData> ResultList;
	ActionFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetSliderFunction() const
{
	TArray<FFunctionData> ResultList;
	SliderFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetColorFunction() const
{
	TArray<FFunctionData> ResultList;
	ColorFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetBooleanFunction() const
{
	TArray<FFunctionData> ResultList;
	BooleanFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetStringFunction() const
{
	TArray<FFunctionData> ResultList;
	StringFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetIntFunction() const
{
	TArray<FFunctionData> ResultList;
	IntFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetTextureFunction() const
{
	TArray<FFunctionData> ResultList;
	TextureFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetNameFunction() const
{
	TArray<FFunctionData> ResultList;
	NameFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetVector2DFunction() const
{
	TArray<FFunctionData> ResultList;
	Vector2DFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

TArray<FFunctionData> UFunctionInvokeData::GetVector3DFunction() const
{
	TArray<FFunctionData> ResultList;
	Vector3DFuncList.GenerateValueArray(ResultList);

	if (ResultList.IsEmpty())
	{
		return TArray<FFunctionData>();
	}

	return ResultList;
}

void UFunctionInvokeData::CreateFunctionData()
{
#if WITH_EDITOR
	FString DataPathName = TEXT("/Engine/FunctionInvoke/BP_FuncInvoke");
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


#endif
}

void UFunctionInvokeData::ResetFunctionData()
{
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