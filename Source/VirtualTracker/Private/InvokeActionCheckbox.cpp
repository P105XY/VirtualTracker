// Fill out your copyright notice in the Description page of Project Settings.


#include "InvokeActionCheckbox.h"

UInvokeActionCheckbox::UInvokeActionCheckbox()
{
}

void UInvokeActionCheckbox::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	OnCheckStateChanged.AddDynamic(this, &UInvokeActionCheckbox::FunctionInvoke);
}

void UInvokeActionCheckbox::FunctionInvoke(bool CheckValue)
{
	if (FunctionName.IsNone())
	{
		return;
	}

	BooleanFunctionInvoke(FunctionName, CheckValue);
}
