#pragma once
#include "CoreMinimal.h"
#include "ReloadableInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType) //add projectile types here
namespace EWeaponProjectile
{
	enum ProjectileType
	{
		EBullet UMETA(DisplayName = "Bullet"),
		ESpread UMETA(DisplayName = "Spread"),
		EProjectile UMETA(DisplayName = "Projectile")
	};
}


USTRUCT() //add weapon properties here
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Ammo") // Max ammo 
	int32 MaxAmmo;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo") // Player's current amount of ammo
	int32 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo") // Current ammo in clip
	int32 CurrentAmmoInClip;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo") // Max ammo per cLip
	int32 MaxAmmoInClip;

	UPROPERTY(EditDefaultsOnly, Category = "Config") // damage
	float Damage;;

	UPROPERTY(EditDefaultsOnly, Category = "Config") // reload duration 
	float ReloadDuration;;
	
	UPROPERTY(EditDefaultsOnly, Category = "Config")  // we can set up weapon range based on the type of rifle (Sniper, Shotgun etc) 
	float Range;
	
	UPROPERTY(EditDefaultsOnly, Category = "Config")  // socket name
	FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Config")  // Reloading?
	bool bIsReloading;
	
	UPROPERTY(EditDefaultsOnly, Category = "Config") // to have specific time between shots
	float TimeBetweenShots;
	
	UPROPERTY(EditDefaultsOnly, Category = "Ammo") // we can set up basic cost in bullets for one shot. (Auto, Semi, Burst shooting etc)
	int32 ShotCost;
	
	UPROPERTY(EditDefaultsOnly, Category = "Config") // to achieve more realistic weapon usage experience - not to shoot in the same spot(for example shotgun)
	float WeaponSpread;
	
};


UCLASS()
class CPP_PROJECT_API AWeapon : public AActor, public IReloadableInterface
{
	GENERATED_BODY()

public:	
	
	AWeapon();

	UFUNCTION(BlueprintCallable)
	void Fire();

	/*
	 to use together with projectile types - thus we will be able to configurate what type of the shoot it will be, spread shoot(shotgun), single shoot (pistol, sniper rifle) etc
	UFUNCTION()
	void InstantFire();
	*/
	
	UFUNCTION(BlueprintCallable)//from interface
	virtual bool CanReload() const override;

	UFUNCTION(BlueprintCallable)//from interface
	virtual void Reload() override;
	
	UFUNCTION(BlueprintCallable)
	bool CanFire();

	UFUNCTION(BlueprintCallable)
	void UseAmmo();

	UFUNCTION(BlueprintCallable)
	void WeaponTrace();

	UFUNCTION(BlueprintCallable)
	void ReloadAmmo();
	

	UPROPERTY(EditDefaultsOnly, Category = "Config")//Weapon Config from USTRUCT
	FWeaponData WeaponConfig; 

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config")//Projectile Types
	TEnumAsByte<EWeaponProjectile::ProjectileType> ProjectileType; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision") //Collision
	UBoxComponent* CollisionComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config") //Skeletal Mesh to attach
	USkeletalMeshComponent* WeaponMesh;
	
};

