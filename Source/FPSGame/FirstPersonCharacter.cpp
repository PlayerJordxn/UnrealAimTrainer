// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseSecondaryWeapon.h"
#include "GameFramework/Actor.h"

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

	ABaseSecondaryWeapon* Pistol = GetWorld()->SpawnActor<ABaseSecondaryWeapon>(SecondaryWeapon);
	if (Pistol)
	{
		Pistol->SetActorEnableCollision(false);
		Pistol->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "SOCKET_Weapon");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pistol is nullptr"));
	}
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &AFirstPersonCharacter::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::LookUp);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("OnRun", IE_Pressed, this, &AFirstPersonCharacter::OnRun);
	PlayerInputComponent->BindAction("EndRun", IE_Released, this, &AFirstPersonCharacter::EndRun);

}

void AFirstPersonCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value * MouseSensitivity);
}

void AFirstPersonCharacter::LookRight(float Value) 
{
	AddControllerYawInput(Value * MouseSensitivity);
}

void AFirstPersonCharacter::MoveForward(const float Value)
{
	FVector Forward = GetActorForwardVector();
	AddMovementInput(Forward, Value);
}

void AFirstPersonCharacter::MoveRight(const float Value)
{
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, Value);
}

void AFirstPersonCharacter::OnRun()
{
	UCharacterMovementComponent* Movement = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	Movement->MaxWalkSpeed = Movement->MaxWalkSpeed * 2;
}

void AFirstPersonCharacter::EndRun()
{
	UCharacterMovementComponent* Movement = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	Movement->MaxWalkSpeed = Movement->MaxWalkSpeed / 2;
}

