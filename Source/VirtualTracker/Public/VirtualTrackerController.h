// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VirtualTrackerController.generated.h"

class UFunctionInvokeInputComponent;

/**
 * 
 */
UCLASS()
class VIRTUALTRACKER_API AVirtualTrackerController : public APlayerController
{
	GENERATED_BODY()

public:
	AVirtualTrackerController();

protected:
	virtual void BeginPlay() override;
	virtual void InitInputSystem();

public:
	UFunctionInvokeInputComponent* GetInvokeInput() const;
};
