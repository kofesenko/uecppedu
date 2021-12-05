#pragma once

#include "CoreMinimal.h"
//#include "Camera/CameraComponent.h" //Heavyweight including USpringArmComp
#include "GameFramework/Character.h"
//#include "GameFramework/SpringArmComponent.h" //Heavyweight including USpringArmComp
#include "CharacterWithCamera.generated.h"

class USpringArmComponent; //Lightweight including USpringArmComp
class UCameraComponent; //Lightweight including UCameraComp

UCLASS()
class CPP_PROJECT_API ACharacterWithCamera : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterWithCamera();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	UStaticMeshComponent* MeshComp;
	
	

protected:

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Value);
	void LookUpAtRate(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseLookUpAtRate;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
