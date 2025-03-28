// Fill out your copyright notice in the Description page of Project Settings.


#include "InvokeActionSlider.h"

UInvokeActionSlider::UInvokeActionSlider()
{
}

void UInvokeActionSlider::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	OnValueChanged.AddDynamic(this, &UInvokeActionSlider::FunctionInvoke);
}

void UInvokeActionSlider::FunctionInvoke(float SliderValue)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	SliderFunctionInvoke(FunctionName, SliderValue);
}
