// Fill out your copyright notice in the Description page of Project Settings.


#include "VirtualTrackerController.h"
#include "FunctionInvokeInputComponent.h"
#include "EnhancedPlayerInput.h"

AVirtualTrackerController::AVirtualTrackerController()
{

}

void AVirtualTrackerController::BeginPlay()
{
	Super::BeginPlay();

}

void AVirtualTrackerController::InitInputSystem()
{
	Super::InitInputSystem();

	PlayerInput = NewObject<UFunctionInvokeInputComponent>(this);

	UFunctionInvokeInputComponent* FunctionInputComponent = Cast<UFunctionInvokeInputComponent>(PlayerInput);
	if (!IsValid(FunctionInputComponent))
	{
		return;
	}

	FunctionInputComponent->InitInvokeManager(this);

}

UFunctionInvokeInputComponent* AVirtualTrackerController::GetInvokeInput() const
{
	UFunctionInvokeInputComponent* FunctionInputComponent = Cast<UFunctionInvokeInputComponent>(PlayerInput);
	if (!IsValid(FunctionInputComponent))
	{
		return nullptr;
	}

	return FunctionInputComponent;
}
