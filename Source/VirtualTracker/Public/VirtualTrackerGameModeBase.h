// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FunctionInvokeInterface.h"
#include "VirtualTrackerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API AVirtualTrackerGameModeBase : public AGameModeBase, public IFunctionInvokeInterface
{
	GENERATED_BODY()
	
public:
	AVirtualTrackerGameModeBase();

public:
	UFUNCTION(meta = (ActionFunction))
	void TextInput();

	UFUNCTION(meta = (SliderFunction))
	void SliderInput(float SliderValue);
};
