
#include "Weapon.h"
#include "DrawDebugHelpers.h"

AWeapon::AWeapon()
{
	WeaponConfig.MuzzleSocketName = FName("SM_WeaponSocket");
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	RootComponent = CollisionComp;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	
}

void AWeapon::Fire()
{
	if(CanFire())
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, FString::Printf(TEXT("Current Ammo In Clip = %d"), WeaponConfig.CurrentAmmoInClip));
		UE_LOG(LogTemp, Warning, TEXT("Current Ammo In Clip: %d"), WeaponConfig.CurrentAmmoInClip);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, FString::Printf(TEXT("Current Ammo = %d"), WeaponConfig.CurrentAmmo));
		UE_LOG(LogTemp, Warning, TEXT("Current Ammo: %d"), WeaponConfig.CurrentAmmo);
		WeaponTrace();
		UseAmmo();
	}
}



bool AWeapon::CanReload() const
{
	if(WeaponConfig.CurrentAmmoInClip < WeaponConfig.MaxAmmoInClip && WeaponConfig.CurrentAmmo > 0 && !WeaponConfig.bIsReloading)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::Printf(TEXT("Reloaded")));
		return true;
	}
	return false;
}



void AWeapon::Reload()
{
	if(CanReload())
	{
		WeaponConfig.bIsReloading = false;
	}
	if(WeaponConfig.CurrentAmmoInClip >= 0 && WeaponConfig.CurrentAmmo >= 1)
	{
		WeaponConfig.bIsReloading = true;
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::Printf(TEXT("Reloading")));
		ReloadAmmo();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::White, FString::Printf(TEXT("No Ammo")));
	}
}



bool AWeapon::CanFire()
{
	if(WeaponConfig.CurrentAmmoInClip > 0 && !WeaponConfig.bIsReloading)
	{
		return true;
	}
	return false;
}



void AWeapon::UseAmmo()
{
	WeaponConfig.CurrentAmmoInClip--;
}

void AWeapon::ReloadAmmo()
{
	
	if(WeaponConfig.CurrentAmmo > WeaponConfig.MaxAmmoInClip)
	{
		WeaponConfig.CurrentAmmoInClip = WeaponConfig.CurrentAmmoInClip + WeaponConfig.MaxAmmoInClip - WeaponConfig.CurrentAmmoInClip;
		WeaponConfig.CurrentAmmo = WeaponConfig.CurrentAmmo - WeaponConfig.MaxAmmoInClip;
	}
	else
	{
		WeaponConfig.CurrentAmmoInClip = WeaponConfig.CurrentAmmoInClip + WeaponConfig.CurrentAmmo;
	}

	WeaponConfig.bIsReloading = false;
	
}


void AWeapon::WeaponTrace()
{
	FVector Start = WeaponMesh->GetSocketLocation(WeaponConfig.MuzzleSocketName);
	FVector End = Start + WeaponMesh->GetForwardVector() * WeaponConfig.Range;

	FHitResult Hit(ForceInit);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.0f); //Draw linetrace
	if(GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params))
	{
		if(AActor* Actor = Hit.GetActor())
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, FString::Printf(TEXT("We hit: %s"), *Hit.GetActor()->GetName()));
			UE_LOG(LogTemp, Warning, TEXT("We hit:%s"), *Hit.GetActor()->GetName());
		}
	}
}