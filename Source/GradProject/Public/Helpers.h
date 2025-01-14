#pragma once

#include "CoreMinimal.h"
#include "Helpers.generated.h"

//UENUM(BlueprintType)
//enum class EAIStates : uint8
//{
//	Waiting             UMETA(DisplayName = "WanderAround"),
//	Thinking            UMETA(DisplayName = "Following"),
//	Following           UMETA(DisplayName = "Following"),
//	WanderingAround     UMETA(DisplayName = "WanderingAround"),
//	Generating          UMETA(DisplayName = "Generating"),
//};

UENUM(BlueprintType)
enum class ECommonColors : uint8
{
	Red         UMETA(DisplayName = "Red"),
	Green       UMETA(DisplayName = "Green"),
	Blue        UMETA(DisplayName = "Blue"),
	Yellow      UMETA(DisplayName = "Yellow"),
	Orange      UMETA(DisplayName = "Orange"),
	Purple      UMETA(DisplayName = "Purple"),
	Pink        UMETA(DisplayName = "Pink"),
	Brown       UMETA(DisplayName = "Brown"),
	Black       UMETA(DisplayName = "Black"),
	White       UMETA(DisplayName = "White"),
	Cyan        UMETA(DisplayName = "Cyan"),
	Magenta     UMETA(DisplayName = "Magenta")
};

UCLASS()
class GRADPROJECT_API UColorMappingHelper : public UObject
{
	GENERATED_BODY()

public:

	// Maps ECommonColors to FLinearColor, callable from both C++ and Blueprints
	UFUNCTION(BlueprintCallable, Category = "Color")
	static FLinearColor GetLinearColor(ECommonColors Color)
	{
		switch (Color)
		{
		case ECommonColors::Red:
			return FLinearColor::Red;
		case ECommonColors::Green:
			return FLinearColor::Green;
		case ECommonColors::Blue:
			return FLinearColor::Blue;
		case ECommonColors::Yellow:
			return FLinearColor(1.0f, 1.0f, 0.0f); // RGB for Yellow
		case ECommonColors::Orange:
			return FLinearColor(1.0f, 0.5f, 0.0f); // RGB for Orange
		case ECommonColors::Purple:
			return FLinearColor(0.5f, 0.0f, 0.5f); // RGB for Purple
		case ECommonColors::Pink:
			return FLinearColor(1.0f, 0.4f, 0.7f); // RGB for Pink
		case ECommonColors::Brown:
			return FLinearColor(0.6f, 0.3f, 0.0f); // RGB for Brown
		case ECommonColors::Black:
			return FLinearColor::Black;
		case ECommonColors::White:
			return FLinearColor::White;
		case ECommonColors::Cyan:
			return FLinearColor(0.0f, 1.0f, 1.0f); // RGB for Cyan
		case ECommonColors::Magenta:
			return FLinearColor(1.0f, 0.0f, 1.0f); // RGB for Magenta
		default:
			return FLinearColor::Black; // Default color
		}
	}

	UFUNCTION(BlueprintCallable, Category = "Color")
	ECommonColors StringToEnumCustom(const FString& ColorName)
	{
		if (ColorName.Equals(TEXT("Red"), ESearchCase::IgnoreCase)) return ECommonColors::Red;
		if (ColorName.Equals(TEXT("Green"), ESearchCase::IgnoreCase)) return ECommonColors::Green;
		if (ColorName.Equals(TEXT("Blue"), ESearchCase::IgnoreCase)) return ECommonColors::Blue;
		if (ColorName.Equals(TEXT("Yellow"), ESearchCase::IgnoreCase)) return ECommonColors::Yellow;
		if (ColorName.Equals(TEXT("Orange"), ESearchCase::IgnoreCase)) return ECommonColors::Orange;
		if (ColorName.Equals(TEXT("Purple"), ESearchCase::IgnoreCase)) return ECommonColors::Purple;
		if (ColorName.Equals(TEXT("Pink"), ESearchCase::IgnoreCase)) return ECommonColors::Pink;
		if (ColorName.Equals(TEXT("Brown"), ESearchCase::IgnoreCase)) return ECommonColors::Brown;
		if (ColorName.Equals(TEXT("Black"), ESearchCase::IgnoreCase)) return ECommonColors::Black;
		if (ColorName.Equals(TEXT("White"), ESearchCase::IgnoreCase)) return ECommonColors::White;

		// Default or error value
		return ECommonColors::Black;
	}
};


