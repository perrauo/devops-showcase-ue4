// Fill out your copyright notice in the Description page of Project Settings.

#include "DevopsGameInstance.h"

#include "Misc/NetworkVersion.h"

void UDevopsGameInstance::Init()
{
#if !UE_BUILD_SHIPPING
	FNetworkVersion::IsNetworkCompatibleOverride.BindLambda([](
	uint32 LocalNetworkVersion
	, uint32 RemoteNetworkVersion
	)
	{
		return true;
	});
#endif
}