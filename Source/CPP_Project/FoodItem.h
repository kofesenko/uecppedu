#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/*Food item that heals the player*/
UCLASS()
class CPP_PROJECT_API UFoodItem : public UItem
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float HealthToHeal;

	
protected:
	virtual void Use(ACPP_ProjectCharacter* Character) override;
	
	
};
