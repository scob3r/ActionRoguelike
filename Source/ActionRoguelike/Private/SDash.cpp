// Fill out your copyright notice in the Description page of Project Settings.


#include "SDash.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASDash::ASDash()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

}

// Called when the game starts or when spawned
void ASDash::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASDash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASDash::Teleport()
{
	FVector Loc = SphereComp->GetRelativeLocation();
	SphereComp->GetRelativeRotation();
	TeleportTo(SphereComp->GetRelativeLocation(), SphereComp->GetRelativeRotation(), false, false);
}

