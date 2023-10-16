// Fill out your copyright notice in the Description page of Project Settings.


#include "VP_SaveLoadSystem.h"

#include "DDSFile.h"
#include "Kismet/GameplayStatics.h"

void UVP_SaveLoadSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

bool UVP_SaveLoadSystem::LoadGameFromSlot(EVP_SaveGameSlot Slot)
{
	const FString SlotName = UEnum::GetValueAsString(Slot);
	if( UGameplayStatics::DoesSaveGameExist(SlotName,0))
	{
		UGameplayStatics::LoadGameFromSlot(SlotName,0);
		return true;
	}

	return false;
}

bool UVP_SaveLoadSystem::SaveGameToSlot(EVP_SaveGameSlot Slot)
{
	const FString SlotName = UEnum::GetValueAsString(Slot);
	if(SaveGameObject)
	{
		SaveGameObject->Slot = Slot;
		UGameplayStatics::SaveGameToSlot(SaveGameObject,SlotName, 0);
	}
	else
	{
		SaveGameObject = Cast<UVP_SaveGame>(UGameplayStatics::CreateSaveGameObject(UVP_SaveGame::StaticClass()));
		UGameplayStatics::SaveGameToSlot(SaveGameObject,SlotName, 0);
	}
	
	return SaveGameObject != nullptr;
}

void UVP_SaveLoadSystem::DeleteGameFrom(EVP_SaveGameSlot Slot)
{
	const FString SlotName = UEnum::GetValueAsString(Slot);
	UGameplayStatics::DeleteGameInSlot(SlotName, 0);
}

void UVP_SaveLoadSystem::SetSaveDataInSaveGameObject(FVP_SaveData SaveData, bool Autosave, EVP_SaveGameSlot Slot)
{
	if(SaveGameObject)
	{
		SaveGameObject->SaveData = SaveData;
	}
	else
	{
		SaveGameObject = Cast<UVP_SaveGame>(UGameplayStatics::CreateSaveGameObject(UVP_SaveGame::StaticClass()));
		SaveGameObject->SaveData = SaveData;
	}

	if(Autosave)
	{
		SaveGameToSlot(Slot);
	}
}

bool UVP_SaveLoadSystem::GetSaveDataFromSaveGameObject(FVP_SaveData &SaveData) const
{
	if(SaveGameObject)
	{
		SaveData = SaveGameObject->SaveData;
		return true;
	}
	
	return false;
}

// ToDo: Research how to get Length of Enum
int32 UVP_SaveLoadSystem::GetNumberOfSlots()
{
	return EVP_SaveGameSlot::Length;
}

// ToDo: Research how to get EnumValue by int32
EVP_SaveGameSlot UVP_SaveLoadSystem::GetSlotNameByIndex(int32 Index)
{
	switch (Index)
	{
		case 0:
			return EVP_SaveGameSlot::VP_SafeGameSlot_01;
		case 1:
			return EVP_SaveGameSlot::VP_SafeGameSlot_02;
		case 2:
			return EVP_SaveGameSlot::VP_SafeGameSlot_03;

		default: return VP_SafeGameSlot_01;

		
	}
}

EVP_SaveGameSlot UVP_SaveLoadSystem::GetCurrentSaveGameSlot() const
{
	if(SaveGameObject)
	{
		return SaveGameObject->Slot;
	}
	
	return None;
}
