#pragma once

#include "VP_SaveData.generated.h"

USTRUCT(BlueprintType)
struct FVP_SaveData_Player
{

	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HealthCurrent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HealthMax;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Coins;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector LastSavedTransform;
};

USTRUCT(BlueprintType)
struct FVP_SaveData
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVP_SaveData_Player PlayerSaveData;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString LastSavedLevel;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString LastTimeSaved;
	
};

UENUM(BlueprintType)
enum EVP_SaveGameSlot : uint8
{
	VP_SafeGameSlot_01 UMETA(DisplayName = "Slot 01"),
	VP_SafeGameSlot_02 UMETA(DisplayName = "Slot 02"),
	VP_SafeGameSlot_03 UMETA(DisplayName = "Slot 03"),

	Length = 3		   UMETA(Hidden),
	None = 4
};