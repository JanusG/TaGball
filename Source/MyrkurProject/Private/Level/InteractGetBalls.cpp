// Fill out your copyright notice in the Description page of Project Settings.

// Help print debug strings
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf(TEXT(text), fstring))


#include "Level/InteractGetBalls.h"
#include "Kismet/GameplayStatics.h"
#include "Character/MyrkurProjectCharacter.h"

AInteractGetBalls::AInteractGetBalls()
{
	// get self referece for dynamic linkage
	AInteractGetBalls* self = &(*this);
	self->Interact();
}

void AInteractGetBalls::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractGetBalls::Interact()
{
	Super::Interact();
	player = Cast<AMyrkurProjectCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	// give player balls if he asks for them, sets them o maximum ammount of balls
	if (player != NULL)
	{
		player->SetBallsToMax();
	}
	
}