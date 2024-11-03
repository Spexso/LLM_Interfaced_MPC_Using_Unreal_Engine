// Copyright Epic Games, Inc. All Rights Reserved.

#include "GradProjectGameMode.h"
#include "GradProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGradProjectGameMode::AGradProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
