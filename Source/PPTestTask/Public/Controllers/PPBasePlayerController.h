// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PPBasePlayerController.generated.h"

class UPPRoundWidget;
UCLASS()
class PPTESTTASK_API APPBasePlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    UFUNCTION(Client, Reliable)
    void InitRounWidget();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(Client, Reliable)
    void SetVisibilytyBorder(bool Value);

    UFUNCTION(Client, Reliable)
    void SetRedPoint(int32 Value);

    UFUNCTION(Client, Reliable)
    void SetBluePoint(int32 Value);

    UFUNCTION(Client, Reliable)
    void SetCounter(int32 Value);

    UFUNCTION(Client, Reliable)
    void SetVisibilytyBeforeBox(bool Value);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UPPRoundWidget> RoundWidgetClass;

private:
    UPROPERTY(Replicated)
    UPPRoundWidget* RoundWidget;
};
