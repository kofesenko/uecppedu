#include "FoodItem.h"
#include "CPP_ProjectCharacter.h"
#include "InventoryComponent.h"

void UFoodItem::Use(ACPP_ProjectCharacter* Character)
{
	if(Character)
	{
		Character->Health += HealthToHeal; //heal player

		if(OwningInventory)
		{
			OwningInventory->RemoveItem(this); //remove consumed item
		}
	}
}
