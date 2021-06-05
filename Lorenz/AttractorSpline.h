// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttractorSpline.generated.h"

UCLASS()
class LORENZ_API AAttractorSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttractorSpline();

	//UPROPERTY(BlueprintReadWrite)
	//FVector& Location;
	//UPROPERTY(BlueprintReadWrite)
	//FString hello;
	UPROPERTY(BlueprintReadWrite)
	FString hello;
	UPROPERTY(BlueprintReadWrite)
	FVector LocationC;
	int Nout;

private:
	float x, y, z;
	float dxdt, dydt, dzdt;

	UPROPERTY() FVector dLocationdt;
	float p, r, b;
	UPROPERTY() FVector k1;
	UPROPERTY() FVector k2;
	UPROPERTY() FVector k3;
	UPROPERTY() FVector k4;
	float dt;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Test
	UPROPERTY(EditAnyWhere)
	UStaticMeshComponent* SampleMesh;

	UFUNCTION(BlueprintCallable)
	void dosomething();
    //make spline


	UFUNCTION(BlueprintCallable)
	FVector playonce(FVector Loc);

	//RK4loop
	FVector RK4loop(FVector Loc);
	//Lorenz
	FVector Lorenz(FVector Loc);
	//RK4
	FVector RK4(FVector Loc);
};
