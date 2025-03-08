#pragma once

#include "Engine/DataTable.h"
#include "dataGame.h"
#include "PaperSprite.h"
#include "dataTables.generated.h"

USTRUCT(BlueprintType)
struct FdataLangMenu : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tKor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tEng;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tChn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tJpn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tRss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString tSpn;
};

USTRUCT(BlueprintType)
struct FSpriteTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strPath;
};

USTRUCT(BlueprintType)
struct FTextureTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		UTexture2D* sprite;
};

USTRUCT(BlueprintType)
struct FEquipLevelTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valUpgrade;
};

USTRUCT(BlueprintType)
struct FEquipClassTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int maxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valNeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valChunk;
};

USTRUCT(BlueprintType)
struct FGoodsTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valShame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secGoods;
};

USTRUCT(BlueprintType)
struct FTeamLevelTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valReward;
};

USTRUCT(BlueprintType)
struct FHeroLevelTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float spdMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valTreasure;
};

USTRUCT(BlueprintType)
struct FMonsterTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float spdMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secDefAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxDefAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timDefAttack;
};

USTRUCT(BlueprintType)
struct FBulletTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secBounceHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secBounceOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secAfterHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxAfterHit;
};

USTRUCT(BlueprintType)
struct FItemTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSlot;
};


USTRUCT(BlueprintType)
struct FWeaponTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxHeroSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxWeaponSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString spdMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString timOutMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString timAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxbullet; //

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString bulSame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString bulCombo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString timCombo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxDual;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxCombine;

};

USTRUCT(BlueprintType)
struct FBuffTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valLevel;
};


USTRUCT(BlueprintType)
struct FStageTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString timStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString timEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxMonster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString maxSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString secSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString perMoney; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString colMonster; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valReward;
};

USTRUCT(BlueprintType)
struct FGameLevelTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valEXP;
};

USTRUCT(BlueprintType)
struct FCameraTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float valHeight;
};

USTRUCT(BlueprintType)
struct FMarketTreasureTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isAD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lstIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lstVal;
};

USTRUCT(BlueprintType)
struct FMarketDummyTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		UTexture2D* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isFree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isAD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EPAYSection::Type> secPayble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valPay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EPAYSection::Type> secGet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valGet;
};

USTRUCT(BlueprintType)
struct FEvolutionListTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString lstIdxPay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString lstValPay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString lstIdxGet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString lstValGet;
};

USTRUCT(BlueprintType)
struct FEvolutionInfoTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strNAme;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;
};

USTRUCT(BlueprintType)
struct FChallengeInfoTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString valReward;
};
