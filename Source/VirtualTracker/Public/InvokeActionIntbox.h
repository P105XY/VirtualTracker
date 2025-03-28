// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpinBox.h"
#include "FunctionInvokeInterface.h"
#include "InvokeActionIntbox.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API UInvokeActionIntbox : public USpinBox, public IFunctionInvokeInterface
{
	GENERATED_BODY()

public:
	UInvokeActionIntbox();

protected:
	virtual void OnWidgetRebuilt() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Invoke Function Name"))
	FName FunctionName;

public:
	UFUNCTION()
	void FunctionInvoke(float IntagerValue);
};
