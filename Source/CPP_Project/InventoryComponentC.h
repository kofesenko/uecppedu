
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemsC.h"
#include "InventoryComponentC.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated); //BP will bind to this to update UI

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_PROJECT_API UInventoryComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponentC();

	virtual void BeginPlay() override;

	bool AddItem(class UItemC* Item);
	bool RemoveItem(class UItemC* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class UItemC*> DefaultItems;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 Capacity;

	UPROPERTY(BlueprintAssignable, Category = "Inventory");
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<class UItem*> Items;

	

};
