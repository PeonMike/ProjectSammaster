// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PSHUD.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UPSUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class PROJECTSAMMASTER_API APSHUD : public AHUD
{
	GENERATED_BODY()
	

public:

	UPROPERTY()
	TObjectPtr<UPSUserWidget> OverlayWidget;


	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPSUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
