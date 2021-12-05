#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"
UCLASS()
class CPP_PROJECT_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	
	APawnWithCamera();

	UPROPERTY(EditAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Player")
	UStaticMeshComponent* StaticMeshComp;

protected:
	
	/*Variables for input*/
	FVector MovementInput;
	FVector CameraInput;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed; 

	float ZoomFactor;
	float JumpStrength;
	bool bZoomingIn;
	bool bIsJumping;
	
	
	/*Functions for input*/
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	void ZoomIn();
	void ZoomOut();
	void StartJump();
	void EndJump();
	

public:	
	
	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
