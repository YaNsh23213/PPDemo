// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/PPBaseBollActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "CollisionQueryParams.h"

APPBaseBollActor::APPBaseBollActor()
{
    PrimaryActorTick.bCanEverTick = true;
    SceneComponent = CreateDefaultSubobject<USceneComponent>("DefSceneComponent");
    SceneComponent->SetupAttachment(GetRootComponent());

    CollisionFind = CreateDefaultSubobject<USphereComponent>("CollisionFind");
    CollisionFind->SetupAttachment(SceneComponent);

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
    StaticMeshComponent->SetupAttachment(SceneComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
    // MovementComponent->OnProjectileBounce.AddDynamic(this, &APPBaseBollActor::OnCollision);
    if (CollisionFind)
    {
        CollisionFind->OnComponentBeginOverlap.AddDynamic(this, &APPBaseBollActor::OnCollision);
    }
}

void APPBaseBollActor::InitImpuls(FVector Vector)
{
    Vector.Z = 0;
    FRotator NewRotation = FRotationMatrix::MakeFromX(Vector.GetSafeNormal()).Rotator();
    MovementComponent->Velocity = Vector * MovementComponent->InitialSpeed;
    SetActorRotation(NewRotation);
}

void APPBaseBollActor::BeginPlay()
{
    Super::BeginPlay();
    Start = GetActorLocation();
    ImpulseDirection = {FMath::FRandRange(0, 2), FMath::FRandRange(0, 2), 0};
    InitImpuls(ImpulseDirection);
}

void APPBaseBollActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


void APPBaseBollActor::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    UE_LOG(LogTemp, Warning, TEXT("123"));
    FHitResult HitResult;
    auto End = GetActorLocation()+(GetActorForwardVector()*2000);
    auto TargetSpawn = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 20.0f, 0, 1.0f);
    if (HitResult.bBlockingHit)
    {
        FVector ReflectDirectionTemp = UKismetMathLibrary::GetDirectionUnitVector(HitResult.TraceStart, HitResult.TraceEnd);
        FVector ReflectVector = UKismetMathLibrary::GetReflectionVector(ReflectDirectionTemp, HitResult.ImpactNormal);
        InitImpuls(ReflectVector);
        DrawDebugLine(GetWorld(), HitResult.Location, HitResult.Location+(ReflectVector * 2000), FColor::Red, false, 20.0f, 0, 1.0f);
        Start = CollisionFind->GetComponentLocation();
    }
    // OnCollisionClient(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, Hit);
}