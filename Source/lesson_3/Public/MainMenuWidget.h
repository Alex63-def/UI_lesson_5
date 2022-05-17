// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */

class UButton;
class UNativeWidgetHost;

UCLASS(Abstract)
class LESSON_3_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// �������� �� ��������
	virtual void NativeConstruct() override;

	// ������� �� ��������� ��� �������� �������
	virtual void NativeDestruct() override;

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
		UButton* NewGameBtn;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* QuitBtn;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* NewGameAnimation;

	UFUNCTION()
		void OnNewGameClicked();

	UFUNCTION()
		void OnQuitClicked();

	// ��� ��� 4 ����� - ������ ��� ��������� ������� 
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
		UNativeWidgetHost* RadioButtonsHost;

	/*UFUNCTION()
		int32 GetCount() const { return 3; }*/
};
