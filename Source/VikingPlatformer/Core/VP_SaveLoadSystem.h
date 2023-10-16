// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VP_SaveData.h"
#include "VP_SaveGame.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VP_SaveLoadSystem.generated.h"

/**
 * 
 */
UCLASS()
class VIKINGPLATFORMER_API UVP_SaveLoadSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
private:
	
	//Initialize
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	//Current SaveGameObject
	UPROPERTY()
	UVP_SaveGame* SaveGameObject;
	
public:
	
	// Load Save Game
	UFUNCTION(BlueprintCallable, Category = "VikingPlatformer")
	bool LoadGameFromSlot(EVP_SaveGameSlot Slot);
	
	// Save Save Game
	UFUNCTION(BlueprintCallable, Category = "VikingPlatformer")
	bool SaveGameToSlot(EVP_SaveGameSlot Slot);

	//Delete Save Game
	UFUNCTION(BlueprintCallable, Category = "VikingPlatformer")
	void DeleteGameFrom(EVP_SaveGameSlot Slot);

	//Set SaveData in SaveGame
	UFUNCTION(BlueprintCallable, Category = "VikingPlatformer")
	void SetSaveDataInSaveGameObject(FVP_SaveData SaveData, bool Autosave = false, EVP_SaveGameSlot Slot = EVP_SaveGameSlot::VP_SafeGameSlot_01);

	UFUNCTION(BlueprintPure, Category = "VikingPlatformer")
	bool GetSaveDataFromSaveGameObject(FVP_SaveData &SaveData) const;

	//GetNumberOfSlots

	UFUNCTION(BlueprintPure, Category = "VikingPlatformer")
	static int32 GetNumberOfSlots();
	
	//GetSlotNameByIndex
	UFUNCTION(BlueprintPure, Category = "VikingPlatformer")
	static EVP_SaveGameSlot GetSlotNameByIndex(int32 Index);

	UFUNCTION(BlueprintPure, Category = "VikingPlatformer")
	EVP_SaveGameSlot GetCurrentSaveGameSlot() const;
};
