// Fill out your copyright notice in the Description page of Project Settings.


#include "InvokeActionIntbox.h"

UInvokeActionIntbox::UInvokeActionIntbox()
{
}

void UInvokeActionIntbox::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	OnValueChanged.AddDynamic(this, &UInvokeActionIntbox::FunctionInvoke);
}

void UInvokeActionIntbox::FunctionInvoke(float IntagerValue)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	IntFunctionInvoke(FunctionName, IntagerValue);
}
