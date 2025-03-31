// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionInvokeInterface.h"
#include "FunctionInvokeInputComponent.h"
#include "VirtualTrackerController.h"
#include "Kismet/GameplayStatics.h"

// Add default functionality here for any IFunctionInvokeInterface functions that are not pure virtual.


void UFunctionInvokeInstigater::ActionFunctionInvoke(UObject* OuterObject, FName FunctionName)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->ActionFunctionInvoke(FunctionName);
}

void UFunctionInvokeInstigater::SliderFunctionInvoke(UObject* OuterObject, FName FunctionName, float FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);

	if (!IsValid(Input))
	{
		return;
	}

	Input->SliderFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::ColorFunctionInvoke(UObject* OuterObject, FName FunctionName, FLinearColor FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->ColorFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::BooleanFunctionInvoke(UObject* OuterObject, FName FunctionName, bool FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->BooleanFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::StringFunctionInvoke(UObject* OuterObject, FName FunctionName, FString FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->StringFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::IntFunctionInvoke(UObject* OuterObject, FName FunctionName, int32 FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->IntFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::TextureFunctionInvoke(UObject* OuterObject, FName FunctionName)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->TextureFunctionInvoke(FunctionName);
}

void UFunctionInvokeInstigater::NameFunctionInvoke(UObject* OuterObject, FName FunctionName, FName FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->NameFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::Vector2DFunctionInvoke(UObject* OuterObject, FName FunctionName, FVector2D FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);
	if (!IsValid(Input))
	{
		return;
	}

	Input->Vector2DFunctionInvoke(FunctionName, FuncParam);
}

void UFunctionInvokeInstigater::Vector3DFunctionInvoke(UObject* OuterObject, FName FunctionName, FVector FuncParam)
{
	if (!IsValid(this))
	{
		return;
	}

	if (!IsValid(OuterObject))
	{
		return;
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(PlayerController))
	{
		return;
	}

	UFunctionInvokeInputComponent* Input = UFunctionInvokeInputComponent::GetInputComponent(PlayerController);;
	if (!IsValid(Input))
	{
		return;
	}

	Input->Vector3DFunctionInvoke(FunctionName, FuncParam);
}

void IFunctionInvokeInterface::InitInvokeInterface()
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UWorld* World = GEngine->GetWorldFromContextObject(ThisObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!IsValid(World))
	{
		return;
	}

	AVirtualTrackerController* InvokeController = Cast<AVirtualTrackerController>(UGameplayStatics::GetPlayerController(World, 0));
	if (!IsValid(InvokeController))
	{
		return;
	}

	UFunctionInvokeInputComponent* InvokeInputComponent = InvokeController->GetInvokeInput();
	if (!IsValid(InvokeInputComponent))
	{
		return;
	}

	InvokeInputComponent->InitInvokeManager(ThisObject);
}

void IFunctionInvokeInterface::ActionFunctionInvoke(FName FunctionName)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->ActionFunctionInvoke(ThisObject, FunctionName);
}

void IFunctionInvokeInterface::SliderFunctionInvoke(FName FunctionName, float FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->SliderFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::ColorFunctionInvoke(FName FunctionName, FLinearColor FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->ColorFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::BooleanFunctionInvoke(FName FunctionName, bool FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->BooleanFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::StringFunctionInvoke(FName FunctionName, FString FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->StringFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::IntFunctionInvoke(FName FunctionName, int32 FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->IntFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::TextureFunctionInvoke(FName FunctionName)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->TextureFunctionInvoke(ThisObject, FunctionName);
}

void IFunctionInvokeInterface::NameFunctionInvoke(FName FunctionName, FName FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->NameFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::Vector2DFunctionInvoke(FName FunctionName, FVector2D FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->Vector2DFunctionInvoke(ThisObject, FunctionName, FuncParam);
}

void IFunctionInvokeInterface::Vector3DFunctionInvoke(FName FunctionName, FVector FuncParam)
{
	UObject* ThisObject = Cast<UObject>(this);
	if (!IsValid(ThisObject))
	{
		return;
	}

	UFunctionInvokeInstigater* FunctionInvoker = GetInstigator(const_cast<UObject*>(ThisObject));
	if (!IsValid(FunctionInvoker))
	{
		return;
	}

	FunctionInvoker->Vector3DFunctionInvoke(ThisObject, FunctionName, FuncParam);
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

	if (!IsValid(ObjectInstigator))
	{
		if (OuterObject->HasAnyFlags(EObjectFlags::RF_BeginDestroyed))
		{
			return nullptr;
		}
		ObjectInstigator = NewObject<UFunctionInvokeInstigater>(OuterObject, *UFunctionInvokeInstigater::StaticClass()->GetName());
		ObjectInstigator->AddToRoot();
	}

	return ObjectInstigator;
}
