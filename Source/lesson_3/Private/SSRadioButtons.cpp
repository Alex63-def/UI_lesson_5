// Fill out your copyright notice in the Description page of Project Settings.


#include "SSRadioButtons.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSRadioButtons::Construct(const FArguments& InArgs)
{
	OnRadioButtonChanged = InArgs._OnRadioButtonChanged;
	//-----------------------------------------
	//Count = InArgs._Count;
	//										// это вроде не используем сейчас, типа для того что бы как-то автоматически создавать Option(чуть ниже) вместо заготовленных заранее трех)
	//int32 SlotsNum = Count.Get();
	//----------------------------------------
		// с домашки
	Slots = InArgs._Slots;

	int32 SlotsNum = Slots.Get();

	VertBox = SNew(SVerticalBox);

	for (int i = 0; i < SlotsNum; i++)
	{
		TSharedRef<SWidget> RadioButtonItem = CreateCheckBox(i, FString::Printf(TEXT("Option %d"), i + 1));
		VertBox->AddSlot()
			[
				RadioButtonItem
			];
		Map.Add(i, RadioButtonItem);
	}
	ChildSlot
		[
			VertBox.ToSharedRef()
		];

	/*CreateVerticalBox(SlotsNum);

	if (SlotsNum > CurrentIndex)
	{
		CurrentIndex = InArgs._Index.Get();
	}
			
	OnAddSlot.BindSP(this, &SSRadioButtons::OnCountChangedFunc);*/

			// с урока 
	/*ChildSlot
	[*/
		//SNew(SVerticalBox) // распологаем виджеты 
		//+ SVerticalBox::Slot()
		//[
		//	CreateCheckBox(0, TEXT("Option 1"))
		//]
		//+ SVerticalBox::Slot()
		//[
		//	CreateCheckBox(1, TEXT("Option 2"))
		//]
		//+ SVerticalBox::Slot()
		//[
		//	CreateCheckBox(2, TEXT("Option 3"))
		//]

		// еще вариант
		/*
		TSharedPtr<SVerticalBox> Holder = SNew(SVerticalBox);
		Holder->AddSlot()
		[
			CreateCheckBox(0, TEXT("Hello!"))
		];
		ChildSlot
		[
			Holder.ToSharedRef()
		];
		
	];*/
	
}



TSharedRef<SWidget> SSRadioButtons::CreateCheckBox(int32 InIndex, FString InText)
{
	return SNew(SCheckBox) // виджет создается через макрос  SNew
		.IsChecked_Raw(this, &SSRadioButtons::IsChecked, InIndex) // тут спрашиваем через атрибут можем ли мы обновить виджет - мы подвязали функцию
		.OnCheckStateChanged_Raw(this, &SSRadioButtons::OnCheckboxStateChanged, InIndex) // меняет выбранный чекбокс 
		[ // в квадратных скобках создается чайлд 
			SNew(STextBlock)
			.Text(FText::FromString(InText))
		];
}

ECheckBoxState SSRadioButtons::IsChecked(int32 InIndex) const
{
	return InIndex == CurrentIndex ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SSRadioButtons::OnCheckboxStateChanged(ECheckBoxState NewState, int32 InIndex)
{
	if (NewState == ECheckBoxState::Checked)  // смотрим что выбран новый чекбокс 
	{
		CurrentIndex = InIndex; // передаем новому чекбоксу индекс от старогго 
		OnRadioButtonChanged.ExecuteIfBound(CurrentIndex); // сообщаем делегату новый индекс
	}
}

//void SSRadioButtons::OnCountChangedFunc(int32 NewCount)
//{
//	Slots = NewCount;
//	VertBox.Reset();
//	CreateVerticalBox(NewCount);
//}

//void SSRadioButtons::CreateVerticalBox(int32 CountSlots)
//{
//	VertBox = SNew(SVerticalBox);
//
//	for (int i = 0; i < CountSlots; i++)
//	{
//		VertBox->AddSlot()
//			[
//				CreateCheckBox(i, FString::Printf(TEXT("Option %d"), i + 1))
//			];
//		ChildSlot
//			[
//				VertBox.ToSharedRef()
//			];
//	}
//}

void SSRadioButtons::AddNewSlot(FString InText)
{
	int32 NewIndex = VertBox->NumSlots();

	TSharedRef<SWidget> RadioButtonItem = CreateCheckBox(NewIndex, InText);

	VertBox->AddSlot()
		[
			RadioButtonItem
		];
	Map.Add(NewIndex, RadioButtonItem);
}

void SSRadioButtons::RemoveSlot()
{
	if (VertBox->NumSlots() > 0)
	{
		TSharedRef<SWidget> ItemToRemove = Map.FindAndRemoveChecked(VertBox->NumSlots() - 1);
		VertBox->RemoveSlot(ItemToRemove);
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
