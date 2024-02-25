// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AN_TryContinueCombo.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNRPG_API UAN_TryContinueCombo : public UAnimNotify
{
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

private:
	GENERATED_BODY()
};
