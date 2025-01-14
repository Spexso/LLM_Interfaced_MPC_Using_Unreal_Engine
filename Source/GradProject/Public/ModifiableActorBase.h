// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Helpers.h"
#include "ModifiableActorBase.generated.h"


UCLASS()
class GRADPROJECT_API AModifiableActorBase : public AActor
{
	GENERATED_BODY()

public:
	AModifiableActorBase();

	/* Virtual Functions for Modifying the Material Instance */

	UFUNCTION(BlueprintCallable, Category = "CustomMethods")
	virtual void ChangeMaterialColor(FName ParameterName, const FLinearColor& NewColor);

	UFUNCTION(BlueprintCallable, Category = "CustomMethods")
	void ChangeMeshScale(const FVector& NewScale);

	UFUNCTION(BlueprintCallable, Category = "CustomMethods")
	void RotateMesh(const FRotator& NewRotation);

	// Helper to initialize the dynamic material instance
	void InitializeDynamicMaterial();
	
	UFUNCTION(BlueprintCallable)
	FLinearColor GetResolvedColor(ECommonColors Color);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Setup")
	FName ParameterToChange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Setup")
	UMaterialInterface* BaseMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Setup")
	bool bUseInstancedMaterial = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Setup")
	int32 MaterialIndexToEdit = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	UMaterialInstanceDynamic* DynamicMaterialInstance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
