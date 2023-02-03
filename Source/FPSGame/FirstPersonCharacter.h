// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

class UCameraComponent;

UCLASS()
class FPSGAME_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UCameraComponent* Camera;

	void LookUp(float Value) ;
	void LookRight(float Value);
	void MoveForward(const float Value);
	void MoveRight(const float Value);
	void OnRun();
	void EndRun();


	UPROPERTY(EditAnywhere)
	float MouseSensitivity = 5.f;

	UPROPERTY(EditAnywhere)
	float WalkSpeedMultiplier = 1.2f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABaseSecondaryWeapon> SecondaryWeapon;
};
