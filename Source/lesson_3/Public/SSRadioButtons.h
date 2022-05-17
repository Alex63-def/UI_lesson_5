// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

 // ��� � ������ - ������ ����
DECLARE_DELEGATE_OneParam(FOnRadioButtonChanged, int32)

class LESSON_3_API SSRadioButtons : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SSRadioButtons)
	{

	}

	// ������� �������
	SLATE_ATTRIBUTE(int32, Slots);

	SLATE_ATTRIBUTE(int32, Index);

	// ����������� ��� ��� ������ ������ - ����������� ��� ������� - ������ ����������� �� ��������� ������� ��� �����
	SLATE_EVENT(FOnRadioButtonChanged, OnRadioButtonChanged);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs); // ����������� ��� �� ����� �� ����� ����� ���������
	
	FOnRadioButtonChanged OnRadioButtonChanged;

	TAttribute<int32> Slots = 1;

	TSharedPtr<SVerticalBox> VertBox;

	TMap<int32, TSharedRef<SWidget>> Map;

	void AddNewSlot(FString InText);

	void RemoveSlot();

	//// ��� � ��� �����
	//TAttribute<int32> Count;

private:

	// ���������� ������� ������ TSharedRef ��� ��� - �� ��� ������ �������� 
	// ���� ��� �������� ������� ���������� ��������
	TSharedRef<SWidget> CreateCheckBox(int32 InIndex, FString InText);

	int32 CurrentIndex = 0;

	ECheckBoxState IsChecked(int32 InIndex) const;

	void OnCheckboxStateChanged(ECheckBoxState NewState, int32 InIndex);

	
};
