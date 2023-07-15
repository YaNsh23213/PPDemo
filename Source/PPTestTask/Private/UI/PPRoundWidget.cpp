// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/PPRoundWidget.h"
#include "Components/Border.h"
#include "Net/UnrealNetwork.h"
#include "Components/TextBlock.h"

void UPPRoundWidget::AddVisibleBorderWaiting()
{
    if (WaitingBox)
    {
        WaitingBox->SetVisibility(ESlateVisibility::Visible);
    }
}

void UPPRoundWidget::RemoveVisibleBorderWaiting()
{
    if (WaitingBox)
    {
        WaitingBox->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UPPRoundWidget::AddVisibleBeforeBox()
{
    if (BeforeBox)
    {
        BeforeBox->SetVisibility(ESlateVisibility::Visible);
    }
}

void UPPRoundWidget::RemoveVisibleBeforeBox()
{
    if (BeforeBox)
    {
        BeforeBox->SetVisibility(ESlateVisibility::Hidden);
    }
}

void UPPRoundWidget::SetRedPoint(int32 Value)
{
    RedPoint->SetText(FText::FromString(FString::Printf(TEXT("%i"), Value)));
}

void UPPRoundWidget::SetBluePoint(int32 Value)
{
    BluePoint->SetText(FText::FromString(FString::Printf(TEXT("%i"), Value)));
}

void UPPRoundWidget::SetCounterRound(int32 Value)
{
    if (Value == 4)
    {
        CounterRound->SetText(FText::FromString(FString::Printf(TEXT("START"))));
        BeforeBox->SetVisibility(ESlateVisibility::Hidden);
    }
    CounterRound->SetText(FText::FromString(FString::Printf(TEXT("%i"), Value)));
}

void UPPRoundWidget::NativeOnInitialized()
{
    if (WaitingBox)
    {
        // WaitingBox->SetVisibility(ESlateVisibility::Hidden);
    }
    if (BeforeBox)
    {
        BeforeBox->SetVisibility(ESlateVisibility::Hidden);
    }
}
