// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DevopsShowcaseHUD.generated.h"

UCLASS()
class ADevopsShowcaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ADevopsShowcaseHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

