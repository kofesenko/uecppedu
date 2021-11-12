// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharC.generated.h"

UCLASS()
class CPP_PROJECT_API AMainCharC : public ACharacter
{
	GENERATED_BODY()

	/*Invetory*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UInvetoryComponent* Inventory;
	
public:
	
	// Sets default values for this character's properties
	AMainCharC();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float Health;

	UPROPERTY(BlueprintReadWrite)
	float Stamina;

	UFUNCTION(BlueprintCallable, Category = "Items")
	void UseItem (class UItemsC* ItemsC);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
