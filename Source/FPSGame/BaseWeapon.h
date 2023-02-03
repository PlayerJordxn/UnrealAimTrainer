// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class FPSGAME_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:

	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USkeletalMeshComponent* Weapon;

	/* SOCKETS */

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketMagazine;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketIronsights;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketBarrel;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketGrip;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketMagazineReserve;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketScope;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketLaser;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Socket")
	USceneComponent* SocketMuzzle;

	/* MESHES */

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshMagazine;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshIronsightBack;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshBarrel;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshGrip;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshMagazineReserve;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshScope;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshLaser;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshMuzzle;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Mesh")
	UStaticMeshComponent* MeshIronSightFront;
};
