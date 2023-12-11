// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PSCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "PSCharacterEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSAMMASTER_API APSCharacterEnemy : public APSCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	APSCharacterEnemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:

	virtual void BeginPlay() override;
};
