// Fill out your copyright notice in the Description page of Project Settings.


#include "RadioButtonsWidgetStyle.h"

//#include "MyCoreStyle.h"

FRadioButtonsStyle::FRadioButtonsStyle()
{
	// тут делаем стили по умолчанию , иначе ничего не будет в настройках выбрано 
	CheckBoxStyle = FCoreStyle::Get().GetWidgetStyle<FCheckBoxStyle>("RadioButton");

	TextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalUnderlinedText");
}

FRadioButtonsStyle::~FRadioButtonsStyle()
{
}

const FName FRadioButtonsStyle::TypeName(TEXT("FRadioButtonsStyle"));

const FRadioButtonsStyle& FRadioButtonsStyle::GetDefault()
{
	static FRadioButtonsStyle Default;
	return Default;
}

void FRadioButtonsStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them

	// что бы воспользоваться этой функцией сначала обращаемся к супер классу (тут сразу название) а потом к нашим полям
	FSlateWidgetStyle::GetResources(OutBrushes);

	CheckBoxStyle.GetResources(OutBrushes);
	TextStyle.GetResources(OutBrushes);
}

