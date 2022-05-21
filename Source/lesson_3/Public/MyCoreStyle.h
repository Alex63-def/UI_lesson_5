#pragma once

#include "Slate.h"

class LESSON_3_API FMyCoreStyle
{
public:

	static void Initialise();

	static void Shutdown();

	static const ISlateStyle& Get();

private:

	static TSharedPtr<ISlateStyle> StylePtr;
};