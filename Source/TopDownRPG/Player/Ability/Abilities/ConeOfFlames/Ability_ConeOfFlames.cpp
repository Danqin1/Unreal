// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability_ConeOfFlames.h"


// Sets default values
AAbility_ConeOfFlames::AAbility_ConeOfFlames()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAbility_ConeOfFlames::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbility_ConeOfFlames::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbility_ConeOfFlames::Activate(ACharacter* Caster)
{
	Super::Activate(Caster);
}

