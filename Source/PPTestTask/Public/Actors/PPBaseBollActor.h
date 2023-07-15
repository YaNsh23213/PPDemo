// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPBaseBollActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class USceneComponent;
class UProjectileMovementComponent;

UCLASS()
class PPTESTTASK_API APPBaseBollActor : public AActor
{
    GENERATED_BODY()

public:
    APPBaseBollActor();

    UFUNCTION()
    void InitImpuls(FVector Vector);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USphereComponent* CollisionFind;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

     UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UProjectileMovementComponent* MovementComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USceneComponent* SceneComponent;
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    FVector Start;
    FVector ImpulseDirection;
    UFUNCTION()
    void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

};
