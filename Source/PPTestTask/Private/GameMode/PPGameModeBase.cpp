// Fill out your copyright notice in the Description page of Project Settings.

#include "GameMode/PPGameModeBase.h"
#include "UI/PPRoundWidget.h"
#include "Controllers/PPBasePlayerController.h"
#include "UI/PPRoundWidget.h"
#include "Actors/PPBaseBollActor.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/PPBasePlanePawn.h"

void APPGameModeBase::PlayerInit(APlayerController* Controller)
{
    FTimerHandle TimerHandle;
    FTimerDelegate TimerDelegate;
    FTimerHandle TimerHandleInit;
    UE_LOG(LogTemp, Display, TEXT("Added New Player %s"), *Controller->GetName());
    // InitWidget(Controller);
    TimerDelegate.BindUObject(this, &APPGameModeBase::InitWidget, Controller);
    GetWorldTimerManager().SetTimer(TimerHandleInit, TimerDelegate, 2.0f, false);
    AmountPlayer++;
    if (AmountPlayer == 2)
    {
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APPGameModeBase::InitRound, 5.0f, false);
    }
}

void APPGameModeBase::InitRound()
{
    for (auto Element : ArrayController)
    {
        Element->SetVisibilytyBorder(false);
    }
    CurrentCount = 0;
    CurrentTime = 3;
    for (auto Element : ArrayController)
    {
        Element->SetVisibilytyBeforeBox(true);
    }
    GetWorld()->GetTimerManager().SetTimer(EndTimerHandle, this, &APPGameModeBase::TickTimer, 1.0f, true);
}

void APPGameModeBase::EndRound(FString ColorGate)
{
    BaseBollActor->Destroy();
    if (ColorGate == "Red")
    {
        RedPoint++;
    }
    else
    {
        BluePoint++;
    }
    for (auto Element : ArrayController)
    {
        Element->SetRedPoint(RedPoint);
        Element->SetBluePoint(BluePoint);
    }
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APPGameModeBase::InitRound, 1.0f, false);
}

void APPGameModeBase::BeginPlay()
{
    UE_LOG(LogTemp, Warning, TEXT("BeginPlay"))
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);
    for (auto Element : PlayerStarts)
    {
        UE_LOG(LogTemp, Warning, TEXT("Found %s"), *Element->GetName())
    }
}

void APPGameModeBase::TickTimer()
{
    if (CurrentCount == 3)
    {
        BaseBollActor = GetWorld()->SpawnActor<APPBaseBollActor>(BaseBollActorClass);
        FVector Location = {-870, 260, 340};
        BaseBollActor->SetActorLocation(Location);
        for (auto Element : ArrayController)
        {
            Element->SetVisibilytyBeforeBox(false);
            Element->SetCounter(3);
        }
        GetWorld()->GetTimerManager().ClearTimer(EndTimerHandle);

        return;
    }
    for (auto Element : ArrayController)
    {
        Element->SetCounter(CurrentTime);
    }
    CurrentTime--;
    CurrentCount++;
}

void APPGameModeBase::InitWidget(APlayerController* Controller)
{
    const auto BaseController = Cast<APPBasePlayerController>(Controller);
    if (BaseController)
    {
        ArrayController.Add(BaseController);
        BaseController->InitRounWidget();
        BaseController->SetVisibilytyBorder(true);
        UE_LOG(LogTemp, Display, TEXT("AmountPlayer %i"), AmountPlayer);
        auto Actor = GetWorld()->SpawnActor<APPBasePlanePawn>(BasePlanePawnClass);
        Controller->Possess(Actor);
        if (AmountPlayer==1)
        {
            BaseController->GetPawn()->SetActorLocation(PlayerStarts[1]->GetActorLocation());
            auto ControlRotation = BaseController->GetControlRotation();
            ControlRotation.Yaw = ControlRotation.Yaw + 180;
            BaseController->SetControlRotation(ControlRotation);
        }
        else
        {
            BaseController->GetPawn()->SetActorLocation(PlayerStarts[0]->GetActorLocation());

        }

    }
}
