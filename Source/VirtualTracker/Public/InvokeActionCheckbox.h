// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CheckBox.h"
#include "FunctionInvokeInterface.h"
#include "InvokeActionCheckbox.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API UInvokeActionCheckbox : public UCheckBox, public IFunctionInvokeInterface
{
	GENERATED_BODY()
	
public:
	UInvokeActionCheckbox();
	
protected:
	virtual void OnWidgetRebuilt() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Invoke Function Name"))
	FName FunctionName;

public:
	UFUNCTION()
	void FunctionInvoke(bool CheckValue);
};
