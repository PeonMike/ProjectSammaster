// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SammasterCharacter.h"
#include "Player\PSPlayerController.h"
#include "Player\PSPlayerState.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AbilitySystem\PSAbilitySystemComponent.h"
#include "AbilitySystem\PSAttributeSet.h"
#include "UI\HUD\PSHUD.h"



ASammasterCharacter::ASammasterCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ASammasterCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);


	InitAbilityActorInfo();
}

void ASammasterCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void ASammasterCharacter::InitAbilityActorInfo()
{
	APSPlayerState* SammasterPlayerState = GetPlayerState<APSPlayerState>();
	check(SammasterPlayerState);
	SammasterPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SammasterPlayerState, this);
	AbilitySystemComponent = SammasterPlayerState->GetAbilitySystemComponent();
	AttributeSet = SammasterPlayerState->GetAttributeSet();


	if (APSPlayerController* PSPlayerController = Cast<APSPlayerController>(GetController()))
	{
		if (APSHUD* PSHUD = Cast<APSHUD>(PSPlayerController->GetHUD()))
		{
			PSHUD->InitOverlay(PSPlayerController, SammasterPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
