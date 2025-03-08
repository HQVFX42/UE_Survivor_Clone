#pragma once

#include "CoreMinimal.h"
#include "charPlayer.h"
#include "charSystem.h"
#include "charMonster.h"
#include "charBase.h"
#include "charOption.h"
#include "dataGame.h"
#include "actItem.h"

#include "GameFramework/PlayerController.h"
#include "plyctrMaingame.generated.h"

UCLASS()
class TIDALFALTS_API AplyctrMaingame : public APlayerController
{
	GENERATED_BODY()
	
public:

	class dataGame* GameData;

	AcharPlayer* chrPlayer;
	AcharSystem* chrSystem;

	int tmpvalue;

	AplyctrMaingame();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	FMonsterData LoadMonsterData(int idx);
	FItemData LoadItemData(int idx);
	FEquipLevelData LoadEquipLevelData(int slot, int cls);
	FEquipClassData LoadEquipClassData(int cls);
	FHeroLevelData LoadHeroLevelData(int lvl);
	FBulletData LoadBulletData(int idx);
	FWeaponData LoadWeaponData(int sec, int idx, int lvl);
	FBuffData LoadBuffData(int idx, int lvl);
	FGoodsData LoadGoodsData(int idx);
	FStageData LoadStageData(TEnumAsByte<EGameModeSection::Type> sec, int idx);
	FTeamLevelData LoadTeamLevelData(int lvl);
	FEvolutionListData LoadEvolData(int lvl, int idx);
	FEvolutionInfoData LoadEvolInfo(int idx);
	FChallengeInfoData LoadChallengeInfo(int lvl, int idx);
	int LoadGameLevelData(int lvl);
	float LoadCameraData(int idx);

	TArray<FString> getArray(FString str, FString word);
	FString getArrayToString(FString str, FString word, int idx);
	int getArrayToInt(FString str, FString word, int idx);
	float getArrayToFloat(FString str, FString word, int idx);

	FString LoadMonsterSprite(int idx);
	FString LoadEquipSprite(int idx);
	FString LoadItemSprite(int idx);
	FString LoadBulletSprite(int idx);
	FString LoadGoodsSprite(int idx);
	FString LoadSkillSprite(int idx);
	FString LoadEvolSprite(int idx);

	AActor* CreateEffect(FString cls, FVector2D loc, float zoom);
	AcharBase* CreateCharacter(FString cls, int spr, FVector2D loc, float zoom);
	AcharMonster* CreateMonster(int idx, FVector2D loc, TEnumAsByte<EMonsterSection::Type> sec);
	AcharHero* CreateHero(int idx, FVector2D loc);
	AcharOption* CreateOption(FVector2D loc);

	AactBullet* CreateBullet(int idx, FVector2D loc);
	AactItem* CreateGoods(int idx, FVector2D loc);

	FRotator GetDistRotator(FVector posFrom, FVector posTarget);
	FVector GetForwardVector(FRotator InRot);

	FVector2D Get2DFrom3D(FVector WorldPosition);

};
