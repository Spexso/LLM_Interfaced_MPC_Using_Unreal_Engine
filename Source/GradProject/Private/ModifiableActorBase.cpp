// Fill out your copyright notice in the Description page of Project Settings.


#include "ModifiableActorBase.h"

// Sets default values
AModifiableActorBase::AModifiableActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach a StaticMeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void AModifiableActorBase::ChangeMaterialColor(FName ParameterName, const FLinearColor& NewColor)
{
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue(ParameterName, NewColor);
	}
}

// Change the scale of the mesh
void AModifiableActorBase::ChangeMeshScale(const FVector& NewScale)
{
	if (MeshComponent)
	{
		MeshComponent->SetRelativeScale3D(NewScale);
	}
}

// Rotate the mesh
void AModifiableActorBase::RotateMesh(const FRotator& NewRotation)
{
	if (MeshComponent)
	{
		MeshComponent->SetRelativeRotation(NewRotation);
	}
}

void AModifiableActorBase::InitializeDynamicMaterial()
{
	if (MeshComponent)
	{
		if (Material)
		{
			// Create a dynamic material instance
			DynamicMaterialInstance = UMaterialInstanceDynamic::Create(Material, this);
			if (DynamicMaterialInstance)
			{
				// Apply the dynamic material instance to the mesh
				MeshComponent->SetMaterial(0, DynamicMaterialInstance);
			}
		}
	}
}

// Called when the game starts or when spawned
void AModifiableActorBase::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the dynamic material instance
	InitializeDynamicMaterial();
}

// Called every frame
void AModifiableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

