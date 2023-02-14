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

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	void MoveForward(const float Value);
	void MoveRight(const float Value);

	void OnAim();
	void EndAim();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float HorizontalInputValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float VerticalInputValue;

	UFUNCTION(BlueprintImplementableEvent)
	void OnShootEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponSpawnEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReloadEvent();

	UFUNCTION(BlueprintCallable)
	float LerpValue(float From, float To, float Aplha);

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABaseSecondaryWeapon> PrimaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool bIsAiming = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool bIsShooting = false;


};
