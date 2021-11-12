// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItemC.h"
#include "MainCharC.h"

void UFoodItemC::Use(AMainCharC* Character)
{
	if(Character)
	{
		Character->Health += HealthToHeal;
	}
}
