// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PPGameModeBase.generated.h"

class APlayerController;
class UPPRoundWidget;
class APPBasePlayerController;
class APPBaseBollActor;
class APlayerStart;
class APPBasePlanePawn;

UCLASS()
class PPTESTTASK_API APPGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void PlayerInit(APlayerController* Controller);

    UFUNCTION()
    void InitWidget(APlayerController* Controller);

    UFUNCTION()
    void InitRound();

    UFUNCTION()
    void EndRound(FString ColorGate);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<APPBaseBollActor> BaseBollActorClass;

     UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<APPBasePlanePawn> BasePlanePawnClass;

    virtual void BeginPlay() override;

private:
    FTimerHandle EndTimerHandle;

    int32 CurrentCount = 0;
    int32 CurrentTime = 3;
    int32 RedPoint = 0;
    int32 BluePoint = 0;

    UPROPERTY()
    TArray<AActor*> PlayerStarts;

    UFUNCTION()
    void TickTimer();

    UPROPERTY()
    APPBaseBollActor* BaseBollActor;

    UPROPERTY()
    TArray<APPBasePlayerController*> ArrayController;

    UPROPERTY()
    int32 AmountPlayer = 0;
};
