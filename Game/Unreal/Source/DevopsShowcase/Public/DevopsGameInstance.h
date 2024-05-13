// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DevopsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEVOPSSHOWCASE_API UDevopsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;	
};
