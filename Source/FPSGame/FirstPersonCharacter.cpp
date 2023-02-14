// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseSecondaryWeapon.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetMesh(), "SOCKET_Camera");

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Try cast to secondary weapon
	ABaseSecondaryWeapon* MainWeapon = GetWorld()->SpawnActor<ABaseSecondaryWeapon>(PrimaryWeapon);
	//Try cast to primary weapon

	if (MainWeapon)
	{
		MainWeapon->SetActorEnableCollision(false);
		MainWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "SOCKET_Weapon");
	}
	OnWeaponSpawnEvent();
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HorizontalInputValue = AActor::GetInputAxisValue(TEXT("MoveRight"));
	VerticalInputValue = AActor::GetInputAxisValue(TEXT("MoveForward"));
}


// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &AFirstPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("OnAim", IE_Pressed, this, &AFirstPersonCharacter::OnAim);
	PlayerInputComponent->BindAction("EndAim", IE_Released, this, &AFirstPersonCharacter::EndAim);
	PlayerInputComponent->BindAction("OnShoot", IE_Pressed, this, &AFirstPersonCharacter::OnShootEvent);


}

void AFirstPersonCharacter::MoveForward(const float Value)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward * Value);
}

void AFirstPersonCharacter::MoveRight(const float Value)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(Right * Value);
}

void AFirstPersonCharacter::OnAim()
{
	bIsAiming = true;
}

void AFirstPersonCharacter::EndAim()
{
	bIsAiming = false;
}

float AFirstPersonCharacter::LerpValue(float From, float To, float Aplha)
{
	float lerpedvalue = FMath::Lerp(From, To, Aplha);
	return lerpedvalue;
}




