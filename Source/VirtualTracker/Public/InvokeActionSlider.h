// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Slider.h"
#include "FunctionInvokeInterface.h"
#include "InvokeActionSlider.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API UInvokeActionSlider : public USlider, public IFunctionInvokeInterface
{
	GENERATED_BODY()

public:
	UInvokeActionSlider();

protected:
	virtual void OnWidgetRebuilt() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Invoke Function Name"))
	FName FunctionName;

public:
	UFUNCTION()
	void FunctionInvoke(float SliderValue);
};
