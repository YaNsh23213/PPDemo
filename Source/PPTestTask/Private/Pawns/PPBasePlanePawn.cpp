// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/PPBasePlanePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"

APPBasePlanePawn::APPBasePlanePawn()
{
    PrimaryActorTick.bCanEverTick = true;
    SceneComponent = CreateDefaultSubobject<USceneComponent>("DefSceneComponent");
    SceneComponent->SetupAttachment(GetRootComponent());

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmComponent"));
    SpringArmComponent->SetupAttachment(SceneComponent);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp3P"));
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void APPBasePlanePawn::BeginPlay()
{
    Super::BeginPlay();
}

void APPBasePlanePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APPBasePlanePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    PlayerInputComponent->BindAxis("LeftRight", this, &APPBasePlanePawn::MoveLeftRightServer);
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APPBasePlanePawn::MoveLeftRightClient_Implementation(float Amount)
{
    if (GetControlRotation().Yaw > 100)
    {
        auto TempLocation = GetActorLocation();
        TempLocation.Y = TempLocation.Y - Amount;
        SetActorLocation(TempLocation);
    }
    else
    {
        auto TempLocation = GetActorLocation();
        TempLocation.Y = TempLocation.Y + Amount;
        SetActorLocation(TempLocation);
    }
}

void APPBasePlanePawn::MoveLeftRightServer_Implementation(float Amount)
{
    // MoveLeftRightClient_Implementation(Amount);
    MoveLeftRightClient(Amount);
}
