// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VP_SaveData.h"
#include "GameFramework/SaveGame.h"
#include "VP_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class VIKINGPLATFORMER_API UVP_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	TEnumAsByte<EVP_SaveGameSlot> Slot;
	
	UPROPERTY()
	FVP_SaveData SaveData;
	
};
