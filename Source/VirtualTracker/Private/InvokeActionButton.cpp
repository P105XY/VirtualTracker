// Fill out your copyright notice in the Description page of Project Settings.


#include "InvokeActionButton.h"

UInvokeActionButton::UInvokeActionButton()
{
}

void UInvokeActionButton::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	OnClicked.AddDynamic(this, &UInvokeActionButton::FunctionInvoke);
}

void UInvokeActionButton::FunctionInvoke()
{
	if (FunctionName.IsNone())
	{
		return;
	}

	ActionFunctionInvoke(FunctionName);
}

