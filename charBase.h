#pragma once

#include "CoreMinimal.h"
#include "dataGame.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"

#include "GameFramework/Actor.h"
#include "charBase.generated.h"

UCLASS()
class TIDALFALTS_API AcharBase : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharBPState)
	UPaperFlipbookComponent* sprChar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharBPState)
	USphereComponent* colSphere;

	TEnumAsByte<ECharSection::Type> secChar;

	float valHPNow;
	float valHPMax;

	float spdMove;

	float valPower;


	AcharBase();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	void setSprite(FString path);

	void ChangeHP(float val, float max);
};
