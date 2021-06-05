// Fill out your copyright notice in the Description page of Project Settings.


#include "AttractorSpline.h"

// Sets default values
AAttractorSpline::AAttractorSpline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SampleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SampleMesh"));

	hello = "helloCpp";
	Nout = 1;

	p = 10.0;
	r = 28.0;
	b = 8.0 / 3.0;
	dt = 0.01;


}

// Called when the game starts or when spawned
void AAttractorSpline::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAttractorSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAttractorSpline::dosomething()
{
	//Location[1] = 1;
	//Location[0] = 0;
	//Location[2] = 0;

	UE_LOG(LogTemp, Warning, TEXT("Text, %s"),*hello);
	//UE_LOG(LogTemp, Warning, TEXT("hh"));
}

FVector AAttractorSpline::playonce(FVector Loc)
{
	FVector Loc2;
	Loc2 = Loc;

	Loc2 = RK4loop(Loc2);

	return Loc2;
}

FVector AAttractorSpline::RK4loop(FVector Loc)
{
	FVector Loc2;
	Loc2 = Loc;

	for (int i = 1; i <= Nout; i++) {
		Loc2 = RK4(Loc2);
	}
	return Loc2;
}

FVector AAttractorSpline::Lorenz(FVector Loc)
{
	//UPROPERTY()
	FVector dLoc;

	x = Loc[0];
	y = Loc[1];
	z = Loc[2];

	dxdt = -p*x + p*y;
	dydt = -x * z + r * x - y;
	dzdt = x * y - b*z;

	dLoc[0] = dxdt;
	dLoc[1] = dydt;
	dLoc[2] = dzdt;

	//UE_LOG(LogTemp, Warning, TEXT("Text, %s"), *hello);

	return dLoc;
}

FVector  AAttractorSpline::RK4(FVector Loc)
{
	FVector Loc2;

	Loc2 = Loc;

	k1 = Lorenz(Loc2);
	k2 = Lorenz(Loc2 + 0.5*k1*dt);
	k3 = Lorenz(Loc2 + 0.5*k2*dt);
	k4 = Lorenz(Loc2 + k3*dt);

	Loc2 = Loc2 + dt * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;

	UE_LOG(LogTemp, Log, TEXT("MyIntValue=%s"), *Loc2.ToString());

	return Loc2;
}