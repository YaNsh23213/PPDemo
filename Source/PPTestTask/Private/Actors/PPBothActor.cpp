// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PPBothActor.h"
#include "GameMode/PPGameModeBase.h"
#include "Components/BoxComponent.h"
// Sets default values
APPBothActor::APPBothActor()
{
 
	PrimaryActorTick.bCanEverTick = false;
    CollisionFind = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
    CollisionFind->SetupAttachment(GetRootComponent());
    if (CollisionFind)
    {
        CollisionFind->OnComponentBeginOverlap.AddDynamic(this, &APPBothActor::OnCollision);
    }
}

void APPBothActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void APPBothActor::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    auto Gamemode = Cast<APPGameModeBase>(GetWorld()->GetAuthGameMode());
    if (Gamemode)
    {
        Gamemode->EndRound(ColorGate);
    }
}


