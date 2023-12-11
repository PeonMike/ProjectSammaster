// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PSCharacterBase.h"


APSCharacterBase::APSCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* APSCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void APSCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


