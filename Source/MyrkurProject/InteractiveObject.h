// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractiveObject.generated.h"

/**
 * 
 */
UCLASS()
class MYRKURPROJECT_API AInteractiveObject : public AStaticMeshActor
{
	GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInteractiveObject();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

	virtual void Interact();
protected:
private:
};
