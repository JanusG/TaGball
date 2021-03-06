// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

class USkeletalMeshComponent;
class UAnimMontage;

UCLASS()
class MYRKURPROJECT_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Main mesh for enemy */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* CMesh;

	/** Ball Mesh : Location at hands of CharMesh */
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* BallMesh;

public:
	/** Sets default values for this character's properties */
	AEnemyCharacter();

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMyrkurProjectProjectile> ProjectileClass;

	/** Animation for throwing the ball */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UAnimMontage* TrowingAnim;

	/** Animation for the enemy to die */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UAnimMontage* DyingAnim;

		/** Animation for the enemy to die */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UAnimMontage* HitgAnim;

	/** Update players health */
	UFUNCTION(BlueprintCallable, Category = Health)
	void UpdateHealth(float HealthChange);

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Set damage to Actor */
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	/** Players full Health */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Health)
	float FullHealth;

	/** Players CUrrent Health */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Health)
	float CurrentHealth;

	/** Set player Ragdoll*/
	void SetCharacterRagdoll();

	/** Run when the player has lost */
	void PlayerLost();

	void AddGamePoint();

public:	
	/** Called every frame */
	virtual void Tick(float DeltaTime) override;\

	/** reset pawn without restarting the level */
	void Reset() override;

	/** Initialize an attack with animation montage */
	UFUNCTION(BlueprintCallable)
	void InitAttack();

	/** Initialize an attack on the player */
	UFUNCTION(BlueprintCallable)
	void Attack();

	/** Set active weapon visible */
	UFUNCTION(BlueprintCallable)
	void SeteWeaponVisible();

private:
	bool bIsDead = false;
};
