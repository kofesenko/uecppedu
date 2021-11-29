#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIChar.generated.h"

UCLASS()
class CPP_PROJECT_API AAIChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIChar();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float Health;

	UPROPERTY(BlueprintReadOnly)
	float Speed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
