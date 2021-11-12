// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharC.h"

// Sets default values
AAICharC::AAICharC()
{
	Health = 100.f;
	



	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAICharC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAICharC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

