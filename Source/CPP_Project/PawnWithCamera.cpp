

#include "PawnWithCamera.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

APawnWithCamera::APawnWithCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	
	/*Creating components + hierarchy*/
	StaticMeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	StaticMeshComp->SetupAttachment(RootComponent);
	SpringArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SpringArmComp,USpringArmComponent::SocketName);

	
	/*SpringArmConfig*/
	/*SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.50f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 400.f;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 3.f;
	*/

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	JumpStrength = 1000.f;
	MovementSpeed = 50.f;
}

void APawnWithCamera::MoveForward(float AxisValue)
{
	MovementInput.X = FMath::Clamp(AxisValue, -1.f, 1.f);
}

void APawnWithCamera::MoveRight(float AxisValue)
{
	MovementInput.Y  = FMath::Clamp(AxisValue, -1.f, 1.f);
}

void APawnWithCamera::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void APawnWithCamera::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void APawnWithCamera::ZoomIn()
{
	bZoomingIn = true;
}

void APawnWithCamera::ZoomOut()
{
	bZoomingIn = false;
	StaticMeshComp->AddImpulse(StaticMeshComp->GetUpVector() * JumpStrength * StaticMeshComp->GetMass());
}

void APawnWithCamera::StartJump()
{
	bIsJumping = true;
	
}

void APawnWithCamera::EndJump()
{
	bIsJumping = false;
}

void APawnWithCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*Zoom*/
	{
		if(bZoomingIn)
		{
			ZoomFactor += DeltaTime / 0.5f;
		}
		else
		{
			ZoomFactor -= DeltaTime / 0.25f;
		}
		ZoomFactor = FMath::Clamp(ZoomFactor, 0.f, 1.f);
		CameraComp->FieldOfView = FMath::Lerp(90.f, 60.f, ZoomFactor);
		SpringArmComp->TargetArmLength = FMath::Lerp(400.f, 300.f, ZoomFactor);
	}

	/*Rotate actor's yaw*/
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}
	
	/*Rotate actor's pitch*/
	{
		FRotator NewRotation = SpringArmComp->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.X, -80.f, -15.f); //Setting limits so we look down
		SpringArmComp->SetWorldRotation(NewRotation);
	}

	/*Movement based on Movement.X and Movement.Y*/
	{
		if(!MovementInput.IsZero())
		{
			MovementInput = MovementInput.GetSafeNormal() * 100.f;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime * MovementSpeed;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime * MovementSpeed;
			SetActorLocation(NewLocation);
		}
	}

	/*Jump*/
	{
		if(bIsJumping)
		{
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorUpVector() * MovementInput.Z * DeltaTime * MovementSpeed;
			SetActorLocation(NewLocation);
			bIsJumping = false;
		}
	}
	
}

void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*Inputs*/
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &APawnWithCamera::ZoomIn);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &APawnWithCamera::ZoomOut);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APawnWithCamera::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APawnWithCamera::EndJump);
	InputComponent->BindAxis("MoveForward", this, &APawnWithCamera::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APawnWithCamera::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &APawnWithCamera::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &APawnWithCamera::YawCamera);

	

}