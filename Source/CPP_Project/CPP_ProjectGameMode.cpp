// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_ProjectGameMode.h"
#include "CPP_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPP_ProjectGameMode::ACPP_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
