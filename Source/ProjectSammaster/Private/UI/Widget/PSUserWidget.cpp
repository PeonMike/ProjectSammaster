// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/PSUserWidget.h"


void UPSUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
