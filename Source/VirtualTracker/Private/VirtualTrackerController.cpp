// Fill out your copyright notice in the Description page of Project Settings.


#include "VirtualTrackerController.h"
#include "FunctionInvokeInputComponent.h"

AVirtualTrackerController::AVirtualTrackerController()
{
	
}

void AVirtualTrackerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerInput = NewObject<UFunctionInvokeInputComponent>(this);

	UFunctionInvokeInputComponent* FunctionInputComponent = Cast<UFunctionInvokeInputComponent>(PlayerInput);
	if (!IsValid(FunctionInputComponent))
	{
		return;
	}

	FunctionInputComponent->InitInvokeManager(this);
}
