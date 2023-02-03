// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "BaseSecondaryWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API ABaseSecondaryWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
private:

	ABaseSecondaryWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/* SOCKETS */

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketIrontSightFront;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketIrontSightBack;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketRail;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketSlide;

	/* MESHES */

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshRail;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshSlide;

};
