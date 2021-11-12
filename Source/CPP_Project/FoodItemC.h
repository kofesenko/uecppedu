// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsC.h"
#include "FoodItemC.generated.h"

/*Food item that heals the player*/
UCLASS()
class CPP_PROJECT_API UFoodItemC : public UItemsC
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float HealthToHeal;

	
protected:
	virtual void Use(AMainCharC* Character) override;
	
	
};
