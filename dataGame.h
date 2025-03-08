#pragma once

#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

#include "Engine/DataTable.h"
#include "dataGame.generated.h"

#define ITEM_IDX_PAYBLE		0		// 아이템 중 재화 시작 인덱스
#define MAX_PAYBLE			9		// 재화 아이템 갯 수

#define PAYBLE_MONEY		0		// 금화 아이템 인덱스
#define PAYBLE_RUBY			1		// 루브 아이템 인덱스
#define PAYBLE_KEY_0		2		// 키 A 아이템 인덱스
#define PAYBLE_KEY_1		3		// 키 B 아이템 인덱스
#define PAYBLE_KEY_2		4		// 키 C 아이템 인덱스
#define PAYBLE_REBORN		5		// 부활 아이템 인덱스
#define PAYBLE_WATER		6		// 기타 A 아이템 인덱스
#define PAYBLE_HEART		7		// 기타 B 아이템 인덱스
#define PAYBLE_ETC			8		// 기타 C 아이템 인덱스

#define ITEM_IDX_EXTEND		50		// 아이템 중 재화 이외 인덱스
#define MAX_EXTEND			2		// 재화 이외 아이템 갯 수

#define ETC_EXP				ITEM_IDX_EXTEND + 0		// 경험치
#define ETC_HEALTH			ITEM_IDX_EXTEND + 1		// 이동력

#define ITEM_IDX_NEED		100		// 장비 업그레이드 필수 아이템 시작 인덱스
#define ITEM_IDX_NEED_RND	199		// 장비 업그레이드 필수 아이템 랜덤
#define ITEM_IDX_CHUNK		200					// 장비 등급 진화 공통 아이템 시작 인덱스
#define CHUNK_IDX_E			0					// 장비 등급 진화 1단계 공통 아이템 시작 인덱스 
#define CHUNK_IDX_E_RND		CHUNK_IDX_E + 99	// 장비 등급 진화 1단계 공통 아이템 랜덤
#define CHUNK_IDX_HQ		100					// 장비 등급 진화 2단계 공통 아이템 시작 인덱스 
#define CHUNK_IDX_HQ_RND	CHUNK_IDX_HQ + 99	// 장비 등급 진화 2단계 공통 아이템 랜덤
#define CHUNK_IDX_RND		500					// 장비 등급 진화 전체단계 공통 아이템 랜덤

#define ITEM_IDX_EQUIP		1000	// 아이템 중 장비 아이템 인덱스
#define EQUIP_INTERVAL		1000	// 장비 아이템 종류당 범위
#define EQUIP_CLASS_RANGE	10		// 장비 아이템 등급당 범위
#define EQUIP_IDX_RND		(9000 - ITEM_IDX_EQUIP) / EQUIP_INTERVAL	// 장비 아이템 랜덤

#define MAX_WEAPON		6			// 전체 무기 아이템 종류

#define WP_SURIKEN		0
#define WP_PISTOL		1
#define WP_SHOTGUN		2
#define WP_GATLING		3
#define WP_BAT			4
#define WP_SPECIAL		5

#define MAX_ETC			4			// 기타 장비 아이템 종류

#define MAX_EQUIP		6			// 전체 장비 종류

#define EQ_WEAPON		0
#define EQ_NECKLACE		1
#define EQ_GLOVE		2
#define EQ_ARMOR		3
#define EQ_BELT			4
#define EQ_SHOES		5

#define EQUIP_GROW_MONEY	1000	// 장비 업그레이드시 레벨 당 필요한 금화
#define EQUIP_GROW_GAB		3		// 장비 업그레이드시 필요한 스크롤 단위

#define EQ_IDX_ATTACK	0			// 장비품 공격력 인덱스
#define EQ_VAL_ATTACK	3			// 장비품 공격력 범위
#define EQ_IDX_HP		3			// 장비품 체력 인덱스
#define EQ_VAL_HP		3			// 장비품 체력 범위

#define MAX_EQUIP_CLASS	11			// 전체 장비품 등급 종류

#define WEAPON_MAIN		0			// 메인 무기 인덱스
#define WEAPON_SUB		1			// 보조 무기 인덱스
#define WEAPON_SPAWN	2			// 소환 무기 인덱스 (중첩 공격)

#define MAX_SKILL_SELECT		6	// 최대 스킬 선택 갯수
#define MAX_SKILL_WEAPON_LEVEL	6	// 최대 무기 스킬 레벨
#define MAX_SKILL_BUFF_LEVEL	5	// 최대 버프 스킬 레벨

#define SKILL_WEAPON_TYPE	6		// 보조 무기 종류
#define SKILL_BUFF_TYPE		11		// 버프 종류

#define SKILL_IDX_MONEY		100		// 금화 보너스 스킬
#define SKILL_IDX_HP		101		// 체력 보너스 스킬

#define SPAWN_TERM			2.0f	// 몬스터 소환 체크 딜레이
#define SPAWN_DIS_DEF		300.0f	// 몬스터 기반 소환 거리
#define SPAWN_DIS_BOUND		5		// 몬스터 소환 위치
#define SPAWN_DIS_RANGE		10.0f	// 몬스터 소환 범위

#define RESPAWN_DIS_RANGE	500.0f	// 몬스터 재 소환 거리

#define MAX_CAMERA_LEVEL	2		// 카메라 단계 레벨 범위

#define MAX_GOODS			11		// 게임 중 습득 아이템 종류

#define GOODS_IDX_EXP		0		// 습득 아이템 중 경험치 시작 인덱스
#define MAX_EXP				4		// 습득 아이템 중 경험치 종류

#define GOODS_IDX_MONEY		4		// 습득 아이템 중 금화 시작 인덱스
#define MAX_MONEY			4		// 습득 아이템 중 금화 종류

#define GOODS_IDX_MEAT		8		// 습득 아이템 중 고기 인덱스
#define GOODS_IDX_MAGNET	9		// 습득 아이템 중 자석 인덱스
#define GOODS_IDX_BOMB		10		// 습득 아이템 중 폭탄 인덱스
#define GOODS_IDX_SKILLBOX	100		// 습득 아이템 중 스킬 보너스 인덱스

#define MAX_STAGE			10		// 전체 스테이지 갯 수

#define TIME_IRONMAN		3.0f	// 부활 후 무적 시간

#define MAX_AD				4		// 광고 보상 종류

#define AD_MONEY			0
#define AD_RUBY				1
#define AD_TREASURE			2
#define AD_HEALTH			3

#define AD_REF_HEALTH		2
#define AD_REF_RUBY			2
#define AD_REF_MONEY		2
#define AD_REF_TREASURE		1

#define MAX_FREE			2		// 최대 무료 습득 횟 수 

#define FREE_MONEY			0
#define FREE_RUBY			1

#define MAX_EVOL			10		// 최대 진화 레벨 수

#define EVOL_NORMAL			3		// 기본 진화 개 수
#define EVOL_SPECIAL		1		// 특수 진화 개 수
#define IDX_EVOL_SPECIAL	3		// 특수 진화 시작 인덱스

#define MAX_STAGE_MISSION	MAX_STAGE * 3	// 스테이지 진행 보상 개 수

#define VAL_CHALLENGE		3		// 레벨 당 도전 개 수

#define CHEST_NORMAL_PER_LV3	1	// 일반 보물상자 최고 등급 확률
#define CHEST_NORMAL_PER_LV2	5	// 일반 보물상자 중간 등급 확률
#define CHEST_NORMAL_PER_LV1	90	// 일반 보물상자 최하 등급 확률 (나머지가 기본)

#define CHEST_SPECIAL_PER_LV3	1	// 고급 보물상자 최고 등급 확률
#define CHEST_SPECIAL_PER_LV2	5	// 고급 보물상자 중간 등급 확률
#define CHEST_SPECIAL_PER_LV1	10	// 고급 보물상자 최하 등급 확률 (나머지가 기본)



UENUM(BlueprintType)
namespace ESecMenu
{
	enum Type
	{
		None		UMETA(DisplayName = "None"),
		LogIn		UMETA(DisplayName = "LogIn"),
		InGame		UMETA(DisplayName = "InGame"),
	};
}

UENUM(BlueprintType)
namespace ESecSection
{
	enum Type
	{
		None		UMETA(DisplayName = "None"),

		Start		UMETA(DisplayName = "Start"),
		Ready		UMETA(DisplayName = "Ready"),

		Lobby		UMETA(DisplayName = "Lobby"),
		Battle		UMETA(DisplayName = "Battle"),

		Waiting		UMETA(DisplayName = "Waiting"),
		Result		UMETA(DisplayName = "Result"),
	};
}

UENUM(BlueprintType)
namespace EAnimHero
{
	enum Type
	{
		IDLE			UMETA(DisplayName = "IDLE"),
		MOVE			UMETA(DisplayName = "MOVE"),
		DIE				UMETA(DisplayName = "DIE"),
	};
}

UENUM(BlueprintType)
namespace EAnimOption
{
	enum Type
	{
		IDLE			UMETA(DisplayName = "IDLE"),
		MOVE			UMETA(DisplayName = "MOVE"),
		HOP				UMETA(DisplayName = "HOP"),
	};
}

UENUM(BlueprintType)
namespace EAnimOptAttack
{
	enum Type
	{
		NONE			UMETA(DisplayName = "NONE"),
		MOUNT			UMETA(DisplayName = "MOUNT"),
		ACTION			UMETA(DisplayName = "ACTION"),
		RECIEVE			UMETA(DisplayName = "RECIEVE"),
	};
}

UENUM(BlueprintType)
namespace ECharSection
{
	enum Type
	{
		Hero			UMETA(DisplayName = "Hero"),
		Option			UMETA(DisplayName = "Option"),
		Monster			UMETA(DisplayName = "Monster"),
	};
}

UENUM(BlueprintType)
namespace EGameModeSection
{
	enum Type
	{
		NORMAL				UMETA(DisplayName = "NORMAL"),
		CHALLENGE			UMETA(DisplayName = "CHALLENGE"),
	};
}

UENUM(BlueprintType)
namespace EChangeModeSection
{
	enum Type
	{
		MENU_MAIN			UMETA(DisplayName = "MENU_MAIN"),
		GAME_NORMAL			UMETA(DisplayName = "GAME_NORMAL"),
		GAME_CHALLENGE		UMETA(DisplayName = "GAME_CHALLENGE"),
	};
}

UENUM(BlueprintType)
namespace ESpriteSection
{
	enum Type
	{
		MONSTER				UMETA(DisplayName = "MONSTER"),
		EQUIP				UMETA(DisplayName = "EQUIP"),
		ITEM				UMETA(DisplayName = "ITEM"),
		BULLET				UMETA(DisplayName = "BULLET"),
		GOODS				UMETA(DisplayName = "GOODS"),
	};
}

UENUM(BlueprintType)
namespace EPAYSection
{
	enum Type
	{
		CASH				UMETA(DisplayName = "CASH"),
		RUBY				UMETA(DisplayName = "RUBY"),
		MONEY				UMETA(DisplayName = "MONEY"),
	};
}

UENUM(BlueprintType)
namespace EGoodsSection
{
	enum Type
	{
		EXP					UMETA(DisplayName = "EXP"),
		MONEY				UMETA(DisplayName = "MONEY"),
		MEAT				UMETA(DisplayName = "MEAT"),
		MAGNET				UMETA(DisplayName = "MAGNET"),
		BOMB				UMETA(DisplayName = "BOMB"),
		SKILLBOX			UMETA(DisplayName = "SKILLBOX"),
	};
}

UENUM(BlueprintType)
namespace EGoodsMoveSection
{
	enum Type
	{
		NONE				UMETA(DisplayName = "EXP"),
		FARTHER				UMETA(DisplayName = "MONEY"),
		COMING				UMETA(DisplayName = "MEAT"),
	};
}

UENUM(BlueprintType)
namespace EItemSection
{
	enum Type
	{
		ETC					UMETA(DisplayName = "ETC"),
		EQUIP				UMETA(DisplayName = "EQUIP"),
		NEEDS				UMETA(DisplayName = "NEEDS"),
		CHUNK				UMETA(DisplayName = "CHUNK"),
	};
}

UENUM(BlueprintType)
namespace EMonsterSection
{
	enum Type
	{
		ITEM			UMETA(DisplayName = "ITEM"),
		MONSTER			UMETA(DisplayName = "MONSTER"),
		CHAMPION		UMETA(DisplayName = "CHAMPION"),
		BOSS			UMETA(DisplayName = "BOSS"),
	};
}

UENUM(BlueprintType)
namespace EMonsterMoveSection
{
	enum Type
	{
		FOLLOW			UMETA(DisplayName = "FOLLOW"),
		PASS_TARGET		UMETA(DisplayName = "PASS_TARGET"),
	};
}

UENUM(BlueprintType)
namespace EMonsterAttackSection
{
	enum Type
	{
		NONSHOOT		UMETA(DisplayName = "FOLLOW"),
		SHOOT			UMETA(DisplayName = "PASS_TARGET"),
	};
}

UENUM(BlueprintType)
namespace ETargetSection
{
	enum Type
	{
		NONE			UMETA(DisplayName = "NONE"),
		HERO			UMETA(DisplayName = "HERO"),
		MONSTER			UMETA(DisplayName = "MONSTER"),
		BOTH			UMETA(DisplayName = "BOTH"),
	};
}

UENUM(BlueprintType)
namespace EBulletDamageSection
{
	enum Type
	{
		NONE			UMETA(DisplayName = "NONE"),
		STANDARD		UMETA(DisplayName = "STANDARD"),
	};
}

UENUM(BlueprintType)
namespace EBulletMoveSection
{
	enum Type
	{
		BOUND			UMETA(DisplayName = "BOUND"),
		FORWARD			UMETA(DisplayName = "FORWARD"),
		FORWARD_WORM	UMETA(DisplayName = "FORWARD_WORM"),
		FOLLOW			UMETA(DisplayName = "FOLLOW"),
		TURN_LOCK		UMETA(DisplayName = "TURN_LOCK"),
		TURN_MOVE		UMETA(DisplayName = "TURN_MOVE"),
		PLAYER			UMETA(DisplayName = "PLAYER"),
	};
}

UENUM(BlueprintType)
namespace EBulletRotateSection
{
	enum Type
	{
		NONE		UMETA(DisplayName = "NONE"),
		FORWARD		UMETA(DisplayName = "FORWARD"),
		TURN		UMETA(DisplayName = "TURN"),
	};
}

UENUM(BlueprintType)
namespace EBulletBounceHitSection
{
	enum Type
	{
		NONE			UMETA(DisplayName = "NONE"),
		FIND_TARGET		UMETA(DisplayName = "FIND_TARGET"),
		RANDOM			UMETA(DisplayName = "RANDOM"),
		ROT_BASE		UMETA(DisplayName = "ROT_BASE"),
	};
}

UENUM(BlueprintType)
namespace EBulletBounceOutSection
{
	enum Type
	{
		NONE		UMETA(DisplayName = "NONE"),
		RANDOM		UMETA(DisplayName = "RANDOM"),
		ROT_BASE	UMETA(DisplayName = "ROT_BASE"),
	};
}

UENUM(BlueprintType)
namespace EBulletAfterHitSection
{
	enum Type
	{
		DESTROY			UMETA(DisplayName = "DESTROY"),
		PIERCE			UMETA(DisplayName = "PIERCE"),
		SPAWN			UMETA(DisplayName = "SPAWN"),
		CHANGE			UMETA(DisplayName = "CHANGE"),
	};
}

UENUM(BlueprintType)
namespace EBulletTimeoutSection
{
	enum Type
	{
		DESTROY			UMETA(DisplayName = "DESTROY"),
		SPAWN			UMETA(DisplayName = "SPAWN"),
	};
}

UENUM(BlueprintType)
namespace EWaeaponAttackSection
{
	enum Type
	{
		SHOT_AUTO		UMETA(DisplayName = "SHOT_AUTO"),
		SHOT_LOOK		UMETA(DisplayName = "SHOT_LOOK"),
		RADIAL_LOOK		UMETA(DisplayName = "RADIAL_LOOK"),
		CIRCLE			UMETA(DisplayName = "CIRCLE"),
		CLUB_LOOK		UMETA(DisplayName = "CLUB_LOOK"),
		RANDOM			UMETA(DisplayName = "RANDOM"),
	};
}

UENUM(BlueprintType)
namespace ESkillSection
{
	enum Type
	{
		WEAPON			UMETA(DisplayName = "WEAPON"),
		SUB				UMETA(DisplayName = "SUB"),
		BUFF			UMETA(DisplayName = "BUFF"),
		GOLD			UMETA(DisplayName = "GOLD"),
		HP				UMETA(DisplayName = "HP"),
	};
}

UENUM(BlueprintType)
namespace ESound
{
	enum Type
	{
		PopupItem		UMETA(DisplayName = "PopupItem"),
		PopupOpen		UMETA(DisplayName = "PopupOpen"),

		BGMTitle		UMETA(DisplayName = "BGMTitle"),
	};
}

USTRUCT(BlueprintType)
struct FArrayData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lstVal;
};

USTRUCT(BlueprintType)
struct FArticleData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valLevel;
};

USTRUCT(BlueprintType)
struct FHeroSaveData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int64 valEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lstProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int64> lstPayble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lstEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<FArticleData> lstItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valStgClear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<float> timStgRecord;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<FArrayData> lstChallenge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSelectStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EGameModeSection::Type> idxSelectSection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> extraAD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> extraFree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<FArrayData> lstEvol;

};

USTRUCT(BlueprintType)
struct FEquipLevelData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valUpgrade;
};

USTRUCT(BlueprintType)
struct FEquipClassData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int maxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> valNeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> valChunk;
};

USTRUCT(BlueprintType)
struct FGoodsData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valShame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EGoodsSection::Type> secGoods;
};

USTRUCT(BlueprintType)
struct FTeamLevelData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> valReward;
};

USTRUCT(BlueprintType)
struct FHeroLevelData
{
	GENERATED_BODY()

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
struct FMainPlayData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxPlayStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxPlayIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lvlMainWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timMainWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lvlSubWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<float> timSubWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> lvlSubBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timRecover;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> equipWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> equipBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxFinalBuff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int wavNow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int wavMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valKillEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float valEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isRebornAD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isReborn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		bool isClear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timIronman;
};

USTRUCT(BlueprintType)
struct FMonsterData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float spdMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float valHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EMonsterMoveSection::Type> secMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valPower;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EMonsterAttackSection::Type> secDefAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxDefAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timDefAttack;
};

USTRUCT(BlueprintType)
struct FBulletData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSpr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletDamageSection::Type> secDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletMoveSection::Type> secMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletRotateSection::Type> secRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletBounceHitSection::Type> secBounceHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletBounceOutSection::Type> secBounceOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletAfterHitSection::Type> secAfterHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EBulletTimeoutSection::Type> secTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxAfterHit;
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EItemSection::Type> secItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxSlot;
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

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
		float perPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float spdMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timOutMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<EWaeaponAttackSection::Type> secAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxbullet; //

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int bulSame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int bulCombo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timCombo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float valScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxDual;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxCombine;
};


USTRUCT(BlueprintType)
struct FBuffData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float valLevel;
};

USTRUCT(BlueprintType)
struct FWaveData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float timEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idxMonster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int maxSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int secSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float perPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float perSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float perHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float idxEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float perEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float idxMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		float perMoney; // 돈 아니면 아이템

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FLinearColor colMonster;
};

USTRUCT(BlueprintType)
struct FStageData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int valWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<FWaveData> lstWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> valReward;
};

USTRUCT(BlueprintType)
struct FSkillListData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TEnumAsByte<ESkillSection::Type> sec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int idx;
};

USTRUCT(BlueprintType)
struct FSkillInf0Data
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		UPaperSprite* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lvlSkill;
};

USTRUCT(BlueprintType)
struct FEvolutionListData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lstIdxPay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lstValPay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lstIdxGet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		int lstValGet;
};

USTRUCT(BlueprintType)
struct FEvolutionInfoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		UPaperSprite* sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strNAme;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		FString strInfo;
};

USTRUCT(BlueprintType)
struct FChallengeInfoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> idxReward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillData)
		TArray<int> valReward;
};

