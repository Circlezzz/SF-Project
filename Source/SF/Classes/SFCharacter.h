// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Projectile.h"
#include "SFCharacter.generated.h"

//class UInputComponent;

UCLASS()
class ASFCharacter : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FP_Camera;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USceneComponent* FP_FireLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = Particle)
		UParticleSystemComponent* Fire_Particle;

	UPROPERTY()
		bool fire;

public:
	ASFCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		TSubclassOf<AProjectile>Projectile_BP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharInfo)
		int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharInfo)
		float Shoot_Timer;

protected:
	virtual void BeginPlay();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		class UAnimMontage* FireAnimation;

protected:

	void StartFire();
	void StopFire();
	void OnFire();
	void MoveForward(float value);
	void MoveRight(float value);
	void Reload();
	void BeginCrouch();
	void EndCrouch();

};

