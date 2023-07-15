// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PPRoundWidget.generated.h"

class UBorder;
class UTextBlock;

UCLASS()
class PPTESTTASK_API UPPRoundWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UFUNCTION()
    void AddVisibleBorderWaiting();

    UFUNCTION()
    void RemoveVisibleBorderWaiting();

     UFUNCTION()
    void AddVisibleBeforeBox();

    UFUNCTION()
    void RemoveVisibleBeforeBox();

    UFUNCTION()
    void SetRedPoint(int32 Value);

    UFUNCTION()
    void SetBluePoint(int32 Value);

     UFUNCTION()
    void SetCounterRound(int32 Value);

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UBorder* WaitingBox;

    UPROPERTY(meta = (BindWidget))
    UBorder* BeforeBox;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* RedPoint;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* BluePoint;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* CounterRound;
};
