// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SSRadioButtons.h"
#include "RadioButtons.generated.h"

/**
 * 
 */

class SSRadioButtons;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioButtonChangedEvent, int32, NewSelectedButton);

UCLASS()
class LESSON_3_API URadioButtons : public UWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadioButton")
		int32 Slots = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadioButton")
		int32 Index = 0;

	UFUNCTION(BlueprintCallable)
		int32 GetSlots() const { return Slots; };

	UFUNCTION(BlueprintCallable)
		void AddNewSlot(FString InText);

	UFUNCTION(BlueprintCallable)
		void RemoveSlot();

	UPROPERTY(BlueprintAssignable)
		FOnRadioButtonChangedEvent OnRadioButtonChanged;

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

protected:

	virtual TSharedRef<SWidget> RebuildWidget() override;

private:

	TSharedPtr<SSRadioButtons> RadioButtons;

	void OnRadioButtonsChangedFunc(int32 NewSelectedButton);
};
