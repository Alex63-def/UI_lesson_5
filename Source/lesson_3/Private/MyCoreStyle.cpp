#include "MyCoreStyle.h"
//#include "Engine.h"
//#include "SlateBasics.h"
#include "Slate/SlateGameResources.h"
//#include "Styling/ISlateStyle.h"

#define IMAGE_BRUSH(RelativePath, ...) FSlateImageBrush(Style->RootToContentDir(RelativePath, TEXT(".png"), __VA_ARGS__)

TSharedPtr<ISlateStyle>FMyCoreStyle::StylePtr;

TSharedPtr<ISlateStyle> CreateStyle()
{
	// ������ ���� ����� � ��� ���� ���� 

	// ��� ��� ������, ������ ����� ����� � �� (WS_RadioButtons_Default) � ����� ���� ����� ��������� 
	const FString ScopeToDirectory("/Game/WidgetStyle");
	TSharedPtr<ISlateStyle> Style = FSlateGameResources::New(FName("MyCoreStyle"), ScopeToDirectory, ScopeToDirectory);

	// ��� ������ ����� �����
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
	Shutdown(); // �������� �� ������ ������ ���� �������� ��������

	StylePtr = CreateStyle();
	FSlateStyleRegistry::RegisterSlateStyle(*StylePtr); // ������������ ���� ���� ������ � ��������� �������
}

void FMyCoreStyle::Shutdown()
{
	if (StylePtr.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StylePtr); // ������� �� �������� ����������� ������ - ������� ��� ����� ������ ������� ���� ������ � ������ � ������������ ������ � �����������
		StylePtr.Reset();
	}
}

const ISlateStyle& FMyCoreStyle::Get()
{
	if (!StylePtr.IsValid()) // StylePtr ���� �� �������� �� ������� ��� 
	{
		Initialise();
	}
	return *StylePtr;
}
