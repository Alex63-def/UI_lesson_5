// Fill out your copyright notice in the Description page of Project Settings.


#include "RadioButtons.h"

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	RadioButtons.Reset();
}

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	RadioButtons = SNew(SSRadioButtons)
		.OnRadioButtonChanged_UObject(this, &ThisClass::OnRadioButtonsChangedFunc)
		.Slots(Slots)
		.Index(Index);

	return RadioButtons.ToSharedRef();
}

void URadioButtons::OnRadioButtonsChangedFunc(int32 NewSelectedButton)
{
	OnRadioButtonChanged.Broadcast(NewSelectedButton);
}

void URadioButtons::AddNewSlot(FString InText)
{
	if (RadioButtons)
	{
		++Slots;
		RadioButtons->AddNewSlot(InText);
	}
}

void URadioButtons::RemoveSlot()
{
	if (RadioButtons)
	{
		RadioButtons->RemoveSlot();
		if (Slots)
		{
			--Slots;
		}
	}
}