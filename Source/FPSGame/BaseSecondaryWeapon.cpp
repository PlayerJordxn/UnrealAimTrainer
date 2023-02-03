// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSecondaryWeapon.h"

ABaseSecondaryWeapon::ABaseSecondaryWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(Root);

	SocketMagazine = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Magazine"));
	SocketMagazine->SetupAttachment(Weapon, "SOCKET_Magazine");

	MeshMagazine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Magazine"));
	MeshMagazine->SetupAttachment(SocketMagazine);

	SocketIronsights = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Ironsights"));
	SocketIronsights->SetupAttachment(Weapon, "SOCKET_Ironsights");

	SocketIrontSightBack = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Ironsights Back"));
	SocketIrontSightBack->SetupAttachment(SocketIronsights);

	MeshIronsightBack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Ironsights"));
	MeshIronsightBack->SetupAttachment(SocketIrontSightBack);

	SocketBarrel = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Barrel"));
	SocketBarrel->SetupAttachment(Weapon, "SOCKET_Default");

	MeshBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Barrel"));
	MeshBarrel->SetupAttachment(SocketBarrel);

	SocketRail = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Rail"));
	SocketRail->SetupAttachment(Weapon, "SOCKET_Default");

	MeshRail = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Rail"));
	MeshRail->SetupAttachment(SocketRail);

	SocketSlide = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Slide"));
	SocketSlide->SetupAttachment(Weapon, "SOCKET_Slide");

	MeshSlide = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Slide"));
	MeshSlide->SetupAttachment(SocketSlide);

	SocketGrip = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Grip"));
	SocketGrip->SetupAttachment(Weapon, "SOCKET_Grip");

	MeshGrip = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Grip"));
	MeshGrip->SetupAttachment(SocketGrip);

	SocketMagazineReserve = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Magazine Reserve"));
	SocketMagazineReserve->SetupAttachment(Weapon, "SOCKET_Magazine_Reserve");

	MeshMagazineReserve = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Magazine Reserve"));
	MeshMagazineReserve->SetupAttachment(SocketMagazineReserve);

	SocketScope = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Scope"));
	SocketScope->SetupAttachment(Weapon, "SOCKET_Scope");

	MeshScope = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Scope"));
	MeshScope->SetupAttachment(SocketScope);

	SocketLaser = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Laser"));
	SocketLaser->SetupAttachment(Weapon, "SOCKET_Laser");

	MeshLaser = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Laser"));
	MeshLaser->SetupAttachment(SocketLaser);

	SocketMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Muzzle"));
	SocketMuzzle->SetupAttachment(Weapon);

	MeshMuzzle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Muzzle"));
	MeshMuzzle->SetupAttachment(SocketMuzzle);

	SocketIrontSightFront = CreateDefaultSubobject<USceneComponent>(TEXT("Socket Ironsight Front"));
	SocketIrontSightFront->SetupAttachment(SocketIronsights);

	MeshIronSightFront = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Irontsights Front"));
	MeshIronSightFront->SetupAttachment(SocketIrontSightFront);

}

void ABaseSecondaryWeapon::BeginPlay()
{
}

void ABaseSecondaryWeapon::Tick(float DeltaTime)
{
}
