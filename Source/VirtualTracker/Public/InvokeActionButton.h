// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "FunctionInvokeInterface.h"
#include "invokeActionButton.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API UInvokeActionButton : public UButton, public IFunctionInvokeInterface
{
	GENERATED_BODY()
	
public:
	UInvokeActionButton();

protected:
	virtual void OnWidgetRebuilt() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Invoke Function Name"))
	FName FunctionName;

public:
	UFUNCTION()
	void FunctionInvoke();
};
