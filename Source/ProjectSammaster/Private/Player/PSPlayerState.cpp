// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PSPlayerState.h"
#include "AbilitySystem\PSAbilitySystemComponent.h"
#include "AbilitySystem\PSAttributeSet.h"



APSPlayerState::APSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UPSAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* APSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
