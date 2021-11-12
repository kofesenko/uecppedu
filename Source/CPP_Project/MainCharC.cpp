// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharC.h"
#include "ItemsC.h"
#include "InventoryComponentC.h"



// Sets default values
AMainCharC::AMainCharC()
{
	Health = 100.f;
	
	Inventory = CreateDefaultSubobject<UInventoryComponentC>("Inventory");
	Inventory->Capacity = 20;



	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMainCharC::UseItem(UItemsC* ItemsC)
{
	if(ItemsC)
	{
		ItemsC->Use(this);
		ItemsC->OnUse(this); //BP version for using items
	}
}

// Called when the game starts or when spawned
void AMainCharC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

