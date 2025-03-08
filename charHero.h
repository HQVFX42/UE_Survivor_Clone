#pragma once

#include "CoreMinimal.h"
#include "SpineSkeletonRendererComponent.h"
#include "SpineSkeletonAnimationComponent.h"
#include "charOption.h"

#include "charBase.h"
#include "charHero.generated.h"

UCLASS()
class TIDALFALTS_API AcharHero : public AcharBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	USpineSkeletonRendererComponent* renderSpine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
	USpineSkeletonAnimationComponent* animSpine;

	AcharOption* plyOpt;

	TEnumAsByte<EAnimHero::Type> animChar;

	AcharHero();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	float getMaxHP();
	float calAttack();
	float calDefence(float dmg);

	void addDamage(float dmg);
	void setDie();

	void procRecover(float time);
	void procWeapon(float time);
	int setBullet(FWeaponData data);

	UFUNCTION(BlueprintCallable, Category = "CustomFunction")
	void SetAnim(TEnumAsByte<EAnimHero::Type> anim);

	int dir;

	UFUNCTION(BlueprintCallable, Category = "CustomFunction")
	void SetDir(float val);

};
