// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "InventoryComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOPDOWNRPG_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UStaticMeshComponent* WeaponMeleeHandle; // for tests
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UStaticMeshComponent* WeaponMeleeBackIdle; // for tests

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UInputAction* EquipAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UAnimMontage* GetWeaponAnim;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	UAnimMontage* HideWeaponAnim;

	bool bEquippedWeapon = false;
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	float GetCurrentWeaponDamage();
	
	UFUNCTION()
	void ToggleMelee();

	void EquipWeapon();
	void HideWeapon();

	inline bool HasEquippedWeapon() { return bEquippedWeapon; }
};
