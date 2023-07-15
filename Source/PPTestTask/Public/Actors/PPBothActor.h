// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPBothActor.generated.h"

class UBoxComponent;

UCLASS()
class PPTESTTASK_API APPBothActor : public AActor
{
    GENERATED_BODY()

public:
    APPBothActor();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBoxComponent* CollisionFind;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ColorGate;
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
};
