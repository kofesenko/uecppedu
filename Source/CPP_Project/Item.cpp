#include "Item.h"

UItem::UItem()
{
	Weight = 1.0f;
	ItemDisplayName = FText::FromString("Item");
	UseActionText = FText::FromString("Use");
	
}

void UItem::Use(ACPP_ProjectCharacter* Character)
{
	
}

