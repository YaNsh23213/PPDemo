// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PPBasePlanePawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneComponent;


UCLASS()
class PPTESTTASK_API APPBasePlanePawn : public APawn
{
    GENERATED_BODY()

public:
    APPBasePlanePawn();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

     UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USceneComponent* SceneComponent;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    UFUNCTION(Server, Reliable)
    void MoveLeftRightServer(float Amount);

    UFUNCTION(NetMulticast, Reliable)
    void MoveLeftRightClient(float Amount);
};
