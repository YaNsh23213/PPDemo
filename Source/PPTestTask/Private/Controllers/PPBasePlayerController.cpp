// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/PPBasePlayerController.h"
#include "UI/PPRoundWidget.h"
#include "GameMode/PPGameModeBase.h"
#include "Net/UnrealNetwork.h"

void APPBasePlayerController::InitRounWidget_Implementation()
{
    RoundWidget = CreateWidget<UPPRoundWidget>(GetWorld(), RoundWidgetClass);
    RoundWidget->AddToViewport();
}


void APPBasePlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(APPBasePlayerController, RoundWidget);
}

void APPBasePlayerController::SetRedPoint_Implementation(int32 Value)
{
    RoundWidget->SetRedPoint(Value);
}

void APPBasePlayerController::SetBluePoint_Implementation(int32 Value)
{
    RoundWidget->SetBluePoint(Value);
}

void APPBasePlayerController::SetCounter_Implementation(int32 Value)
{
    RoundWidget->SetCounterRound(Value);
}

void APPBasePlayerController::SetVisibilytyBeforeBox_Implementation(bool Value)
{
    if (Value)
    {
        RoundWidget->AddVisibleBeforeBox();
    }
    else
    {
        RoundWidget->RemoveVisibleBeforeBox();
    }
}

void APPBasePlayerController::SetVisibilytyBorder_Implementation(bool Value)
{
    if (Value)
    {
        RoundWidget->AddVisibleBorderWaiting();
    }
    else
    {
        RoundWidget->RemoveVisibleBorderWaiting();
    }
}



void APPBasePlayerController::BeginPlay()
{
    const auto Gamemode = Cast<APPGameModeBase>(GetWorld()->GetAuthGameMode());
    if (Gamemode)
    {
        Gamemode->PlayerInit(this);
    }
}
