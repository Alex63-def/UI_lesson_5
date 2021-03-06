// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "IScorable.h"
#include "BaseProjectile.generated.h"

UCLASS()
class LESSON_3_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

		DECLARE_EVENT(ABaseProjectile, FKillEvent);
		DECLARE_EVENT_OneParam(ABaseProjectile, FExpEvent, FExpData);
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
		float Damage = 1;

	FKillEvent OnKillEvent;
	FExpEvent OnExpEventProjectile;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
