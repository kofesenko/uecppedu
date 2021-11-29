#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class CPP_PROJECT_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

		virtual class UWorld* GetWorld() const
		{
			return World;
		};
		/*Item should know where in the world it is */
		UPROPERTY(Transient)
		class UWorld* World;
	
		/* The text for using the item, for example - Use, Eat, Equip, etc */
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText UseActionText;

		/*The mesh to display for the desired items pickup*/
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* PickupMesh;

		/*The thumbnail for this item in the inventory*/
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
		class UTexture2D* Thumbnail;

		/*The display name for this item in the inventory*/
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

		/*An optional description for this item. Multiline option allows us to create new lines in the editor */
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (Multiline = true))
		FText ItemDescription;
	
		/*The weight for this item. ClampMin option prevents us to have an item in the inventory with weight less than zero*/
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float Weight;

		/*Inventory that owns this item. Items should exist in the inventory so it's good to hav a ref to inventory component*/
		UPROPERTY()
		class UInventoryComponent* OwningInventory;

		/*we should never call use on an item, but we should always call use on a child of an item.*/
		virtual void Use(class ACPP_ProjectCharacter* Character);

		/*BP editable OnUse*/
		UFUNCTION(BlueprintImplementableEvent)
		void OnUse(class ACPP_ProjectCharacter* Character);
	
};




