#include "MyCoreStyle.h"
//#include "Engine.h"
//#include "SlateBasics.h"
#include "Slate/SlateGameResources.h"
//#include "Styling/ISlateStyle.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(Style->RootToContentDir(RelativePath, TEXT(".png"), __VA_ARGS__)

TSharedPtr<ISlateStyle>FMyCoreStyle::StylePtr;

TSharedPtr<ISlateStyle> CreateStyle()
{
	// пример кода будет в спп меин меню 

	// это для ассета, созаем ассет стиля в БП (WS_RadioButtons_Default) и через него можно управлять 
	const FString ScopeToDirectory("/Game/WidgetStyle");
	TSharedPtr<ISlateStyle> Style = FSlateGameResources::New(FName("MyCoreStyle"), ScopeToDirectory, ScopeToDirectory);

	// это только через плюсы
	/*FString Path = FPaths::ProjectContentDir / TEXT("/UI");

	TSharedPtr<ISlateStyleSet> Style = FSlateGameResources::New(FName("MyCoreStyle"), Path, Path);

	Style->Set("Red", FLinearColor::Red);
	Style->Set("DefaultPadding",FMargin(5.0f));
	Style->Set("Frog", new IMAGE_BRUSH("Frog", FVector2D(256.f)));*/

	return Style;
}

#undef IMAGE_BRUSH

void FMyCoreStyle::Initialise()
{
	Shutdown(); // вызываем на всякий случай если окажется валидным

	StylePtr = CreateStyle();
	FSlateStyleRegistry::RegisterSlateStyle(*StylePtr); // регистрируем нашу библ стилей в глобалном реестре
}

void FMyCoreStyle::Shutdown()
{
	if (StylePtr.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StylePtr); // убираем из регистра слейтовских стилей - регистр это фишка движка которая дает доступ к работе с интрументами стилей и библиотекам
		StylePtr.Reset();
	}
}

const ISlateStyle& FMyCoreStyle::Get()
{
	if (!StylePtr.IsValid()) // StylePtr если не валидный то создаем его 
	{
		Initialise();
	}
	return *StylePtr;
}
