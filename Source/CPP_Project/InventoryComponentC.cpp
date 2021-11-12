// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponentC.h"
#include "ItemsC.h"

// Sets default values for this component's properties
UInventoryComponentC::UInventoryComponentC()
{
	Capacity = 20;
}


// Called when the game starts
void UInventoryComponentC::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item :DefaultItems)
	{
		AddItem(Item);
	}
	
}

bool UInventoryComponentC::AddItem(class UItemC* Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		return false;
	}
	
	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);
	
	/*Update UI*/
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponentC::RemoveItem(UItemC* Item)
{
	if(Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}


