// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PSCharacterBase.h"
#include "SammasterCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSAMMASTER_API ASammasterCharacter : public APSCharacterBase
{
	GENERATED_BODY()
	

public:
	ASammasterCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
