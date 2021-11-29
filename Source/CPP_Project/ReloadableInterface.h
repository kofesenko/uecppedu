#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ReloadableInterface.generated.h"


UINTERFACE()
class UReloadableInterface : public UInterface
{
	GENERATED_BODY()
};


class CPP_PROJECT_API IReloadableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION()
	virtual bool CanReload() const = 0;
	
	UFUNCTION()
	virtual void Reload() = 0;
};
