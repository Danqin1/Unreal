// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "TopDownRPG/Interfaces/Enemy.h"
#include "TopDownRPG/Interfaces/EnemyCombat.h"
#include "TopDownRPG/Interfaces/ICharacterState.h"
#include "TopDownRPG/Interfaces/IDamageable.h"
#include "EnemyCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBool, bool)

UCLASS()
class TOPDOWNRPG_API AEnemyCharacter : public ACharacter, public IIDamageable, public IEnemy, public IICharacterState, public IEnemyCombat
{
private:
	GENERATED_BODY()

	bool bIsTracingSword = false;
public:
	FDelegateBool OnAirborne;
	
	AEnemyCharacter();

	virtual ECharacterState GetState() override;
	virtual void SetState(ECharacterState NewState) override;
	virtual void ClearState(ECharacterState State) override;
	
	virtual void OnHit(AActor* Hitter, FVector HitPosition, FVector HitVelocity) override;
	virtual void OnSkillReaction(UAnimMontage* ReactionMontage) override;
	virtual void Damage(float Damage) override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual bool CanDamage() override;
	void SetAirborne(bool isAirborne);
	virtual float Attack() override;
	void StartSwordTrace();
	void EndSwordTrace();
protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponMeshComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Data")
	FName EnemyDataName = "DefaultEnemy";
	
	UPROPERTY(EditDefaultsOnly, Category="Data")
	UDataTable* Data;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	UAnimMontage* HitReactionLeft;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	UAnimMontage* HitReactionRight;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	UAnimMontage* AttackAnimation; /// move to combat component

	UPROPERTY(EditDefaultsOnly)
	UWidgetComponent* LifeBar;
	ECharacterState CurrentState = Nothing;
	float MaxHP = 0;
	float CurrentHP = 0;
	float CurrentDamage = 0;

	bool bIsDead = false;

	void Die();
};
