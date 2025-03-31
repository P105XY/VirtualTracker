// Fill out your copyright notice in the Description page of Project Settings.


#include "VirtualTrackerGameModeBase.h"
#include "FunctionInvokeInputComponent.h"

AVirtualTrackerGameModeBase::AVirtualTrackerGameModeBase()
{

}

void AVirtualTrackerGameModeBase::BeginPlay()
{
	InitInvokeInterface();
}

void AVirtualTrackerGameModeBase::TextInput()
{
	UE_LOG(LogTemp, Log, TEXT("Action Function Input"));
}

void AVirtualTrackerGameModeBase::SliderInput(float SliderValue)
{
	UE_LOG(LogTemp, Log, TEXT("SliderFunction Input"));
}
