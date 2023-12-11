// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/PSAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UPSAttributeSet* PSAttributeSet = CastChecked<UPSAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(PSAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(PSAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(PSAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(PSAttributeSet->GetMaxMana());


	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(PSAttributeSet->GetHealthAttribute()).AddUObject(this, );
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UPSAttributeSet* PSAttributeSet = CastChecked<UPSAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PSAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PSAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PSAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		PSAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
