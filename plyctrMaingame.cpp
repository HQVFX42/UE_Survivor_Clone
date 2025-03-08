#include "plyctrMaingame.h"
#include "dataGame.h"
#include "dataTables.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Components/SkinnedMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

AplyctrMaingame::AplyctrMaingame()
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(0.01666f);
}

void AplyctrMaingame::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

}

void AplyctrMaingame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FMonsterData AplyctrMaingame::LoadMonsterData(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/MonsterData.MonsterData'")));
	FMonsterTable* dataRow = tblObject->FindRow<FMonsterTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FMonsterData tmp = FMonsterData();

	tmp.idxSpr = dataRow->idxSpr;
	tmp.spdMove = dataRow->spdMove;
	tmp.valHP = dataRow->valHP;
	tmp.secMove = static_cast<EMonsterMoveSection::Type>(dataRow->secMove);
	tmp.valPower = dataRow->valPower;
	tmp.secDefAttack = static_cast<EMonsterAttackSection::Type>(dataRow->secDefAttack);
	tmp.idxDefAttack = dataRow->idxDefAttack;
	tmp.timDefAttack = dataRow->timDefAttack;

	return tmp;
}

FItemData AplyctrMaingame::LoadItemData(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/ItemData.ItemData'")));
	FItemTable* dataRow = tblObject->FindRow<FItemTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FItemData tmp = FItemData();

	tmp.idxSprite = dataRow->idxSprite;
	tmp.idxIcon = dataRow->idxIcon;
	tmp.strName = dataRow->strName;
	tmp.secItem = static_cast<EItemSection::Type>(dataRow->secItem);
	tmp.idxSlot = dataRow->idxSlot;

	return tmp;
}

FEquipLevelData AplyctrMaingame::LoadEquipLevelData(int slot, int cls)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EquipLevelData.EquipLevelData'")));
	FEquipLevelTable* dataRow = tblObject->FindRow<FEquipLevelTable>(*FString::Printf(TEXT("%d"), slot), TEXT("DATA"));

	FEquipLevelData tmp = FEquipLevelData();

	tmp.valStart = getArrayToInt(dataRow->valStart, TEXT("/"), cls);
	tmp.valUpgrade = getArrayToInt(dataRow->valUpgrade, TEXT("/"), cls);

	return tmp;
}

FEquipClassData AplyctrMaingame::LoadEquipClassData(int cls)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EquipClassData.EquipClassData'")));
	FEquipClassTable* dataRow = tblObject->FindRow<FEquipClassTable>(*FString::Printf(TEXT("%d"), cls), TEXT("DATA"));

	FEquipClassData tmp = FEquipClassData();

	tmp.strName = dataRow->strName;
	tmp.maxLevel = dataRow->maxLevel;

	TArray<FString> lstNeed;
	dataRow->valNeed.ParseIntoArray(lstNeed, TEXT("/"), true);

	for (int i = 0; i < lstNeed.Num(); i++)
		tmp.valNeed.Add(FCString::Atoi(*lstNeed[i]));

	TArray<FString> lstChunk;
	dataRow->valChunk.ParseIntoArray(lstChunk, TEXT("/"), true);

	for (int i = 0; i < lstChunk.Num(); i++)
		tmp.valChunk.Add(FCString::Atoi(*lstChunk[i]));

	return tmp;
}

FHeroLevelData AplyctrMaingame::LoadHeroLevelData(int lvl)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/HeroLevelData.HeroLevelData'")));
	FHeroLevelTable* dataRow = tblObject->FindRow<FHeroLevelTable>(*FString::Printf(TEXT("%d"), lvl), TEXT("DATA"));

	FHeroLevelData tmp = FHeroLevelData();

	tmp.spdMove = dataRow->spdMove;
	tmp.valPower = dataRow->valPower;
	tmp.valHP = dataRow->valHP;

	return tmp;
}

FBulletData AplyctrMaingame::LoadBulletData(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/BulletData.BulletData'")));
	FBulletTable* dataRow = tblObject->FindRow<FBulletTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FBulletData tmp = FBulletData();

	tmp.idxSpr = dataRow->idxSpr;
	tmp.strPath = dataRow->strPath;
	tmp.secDamage = static_cast<EBulletDamageSection::Type>(dataRow->secDamage);
	tmp.secMove = static_cast<EBulletMoveSection::Type>(dataRow->secMove);
	tmp.secRot = static_cast<EBulletRotateSection::Type>(dataRow->secRot);
	tmp.secBounceHit = static_cast<EBulletBounceHitSection::Type>(dataRow->secBounceHit);
	tmp.secBounceOut = static_cast<EBulletBounceOutSection::Type>(dataRow->secBounceOut);
	tmp.secAfterHit = static_cast<EBulletAfterHitSection::Type>(dataRow->secAfterHit);
	tmp.secTimeout = static_cast<EBulletTimeoutSection::Type>(dataRow->secTimeout);
	tmp.idxAfterHit = dataRow->idxAfterHit;

	return tmp;
}

FWeaponData AplyctrMaingame::LoadWeaponData(int sec, int idx, int lvl)
{
	UDataTable* tblObject;

	if (sec == WEAPON_MAIN)
		tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/WeaponData.WeaponData'")));
	else if (sec == WEAPON_SUB)
		tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/SubWeaponData.SubWeaponData'")));
	else
		tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/SpawnWeaponData.SpawnWeaponData'")));

	FWeaponTable* dataRow = tblObject->FindRow<FWeaponTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FWeaponData tmp = FWeaponData();

	tmp.idxIcon = dataRow->idxIcon;
	tmp.idxHeroSpr = dataRow->idxHeroSpr;
	tmp.idxWeaponSpr = dataRow->idxWeaponSpr;
	tmp.strName = dataRow->strName;
	tmp.strInfo = getArrayToString(dataRow->strInfo, TEXT("/"), lvl);
	tmp.perPower = getArrayToFloat(dataRow->perPower, TEXT("/"), lvl);
	tmp.spdMove = getArrayToFloat(dataRow->spdMove, TEXT("/"), lvl);
	tmp.timOutMove = getArrayToFloat(dataRow->timOutMove, TEXT("/"), lvl);
	tmp.secAttack = static_cast<EWaeaponAttackSection::Type>(dataRow->secAttack);
	tmp.timAttack = getArrayToFloat(dataRow->timAttack, TEXT("/"), lvl);
	tmp.idxbullet = getArrayToInt(dataRow->idxbullet, TEXT("/"), lvl);
	tmp.bulSame = getArrayToInt(dataRow->bulSame, TEXT("/"), lvl);
	tmp.bulCombo = getArrayToInt(dataRow->bulCombo, TEXT("/"), lvl);
	tmp.timCombo = getArrayToFloat(dataRow->timCombo, TEXT("/"), lvl);
	tmp.valScale = getArrayToFloat(dataRow->valScale, TEXT("/"), lvl);
	tmp.idxDual = getArrayToInt(dataRow->idxDual, TEXT("/"), lvl);
	tmp.idxCombine = dataRow->idxCombine;

	return tmp;
}

FBuffData AplyctrMaingame::LoadBuffData(int idx, int lvl)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/BuffData.BuffData'")));
	FBuffTable* dataRow = tblObject->FindRow<FBuffTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FBuffData tmp = FBuffData();

	tmp.idxIcon = dataRow->idxIcon;
	tmp.strName = dataRow->strName;
	tmp.strInfo = getArrayToString(dataRow->strInfo, TEXT("/"), lvl);
	tmp.valLevel = FCString::Atof(*dataRow->valLevel);

	return tmp;
}

FGoodsData AplyctrMaingame::LoadGoodsData(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/GoodsData.GoodsData'")));
	FGoodsTable* dataRow = tblObject->FindRow<FGoodsTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FGoodsData tmp = FGoodsData();

	tmp.idxSpr = dataRow->idxSpr;
	tmp.valShame = dataRow->valShame;
	tmp.secGoods = static_cast<EGoodsSection::Type>(dataRow->secGoods);

	return tmp;
}

FStageData AplyctrMaingame::LoadStageData(TEnumAsByte<EGameModeSection::Type> sec, int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/StageData.StageData'")));
	FStageTable* dataRow = tblObject->FindRow<FStageTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FStageData tmp = FStageData();

	tmp.valWave = dataRow->valWave;

	for (int i = 0; i < tmp.valWave; i++)
	{
		FWaveData data = FWaveData();

		data.timStart = getArrayToFloat(dataRow->timStart, TEXT("/"), i);
		data.timEnd = getArrayToFloat(dataRow->timEnd, TEXT("/"), i);

		data.idxMonster = getArrayToInt(dataRow->idxMonster, TEXT("/"), i);
		data.maxSpawn = getArrayToInt(dataRow->maxSpawn, TEXT("/"), i);
		data.valSpawn = getArrayToInt(dataRow->valSpawn, TEXT("/"), i);
		data.secSpawn = getArrayToInt(dataRow->secSpawn, TEXT("/"), i);

		data.perPower = getArrayToFloat(dataRow->perPower, TEXT("/"), i);
		data.perSpeed = getArrayToFloat(dataRow->perSpeed, TEXT("/"), i);
		data.perHP = getArrayToFloat(dataRow->perHP, TEXT("/"), i);
		data.idxEXP = getArrayToFloat(dataRow->idxEXP, TEXT("/"), i);
		data.perEXP = getArrayToFloat(dataRow->perEXP, TEXT("/"), i);
		data.idxMoney = getArrayToFloat(dataRow->idxMoney, TEXT("/"), i);
		data.perMoney = getArrayToFloat(dataRow->perMoney, TEXT("/"), i);

		FString lst = getArrayToString(dataRow->colMonster, TEXT("/"), i);
		data.colMonster = FLinearColor(FVector(getArrayToFloat(lst, TEXT(","), 0) / 256.f, getArrayToFloat(lst, TEXT(","), 1) / 256.f, getArrayToFloat(lst, TEXT(","), 2) / 256.f));

		tmp.lstWave.Add(data);
	}

	TArray<FString> lstIdx = getArray(dataRow->idxReward, "/");
	for (int i = 0; i < lstIdx.Num(); i++)
		tmp.idxReward.Add(FCString::Atoi(*lstIdx[i]));

	TArray<FString> lstval = getArray(dataRow->valReward, "/");
	for (int i = 0; i < lstval.Num(); i++)
		tmp.valReward.Add(FCString::Atoi(*lstval[i]));

	return tmp;
}

FTeamLevelData AplyctrMaingame::LoadTeamLevelData(int lvl)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/TeamLevelData.TeamLevelData'")));
	FTeamLevelTable* dataRow = tblObject->FindRow<FTeamLevelTable>(*FString::Printf(TEXT("%d"), lvl), TEXT("DATA"));

	FTeamLevelData tmp = FTeamLevelData();

	tmp.valEXP = dataRow->valEXP;

	TArray<FString> lstIdx = getArray(dataRow->idxReward, "/");
	for (int i = 0; i < lstIdx.Num(); i++)
		tmp.idxReward.Add(FCString::Atoi(*lstIdx[i]));

	TArray<FString> lstval = getArray(dataRow->valReward, "/");
	for (int i = 0; i < lstval.Num(); i++)
		tmp.valReward.Add(FCString::Atoi(*lstval[i]));

	return tmp;
}

FEvolutionListData AplyctrMaingame::LoadEvolData(int lvl, int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EvolListData.EvolListData'")));
	FEvolutionListTable* dataRow = tblObject->FindRow<FEvolutionListTable>(*FString::Printf(TEXT("%d"), lvl), TEXT("DATA"));

	FEvolutionListData tmp = FEvolutionListData();

	tmp.lstIdxPay = getArrayToInt(dataRow->lstIdxPay, TEXT("/"), idx);
	tmp.lstValPay = getArrayToInt(dataRow->lstValPay, TEXT("/"), idx);
	tmp.lstIdxGet = getArrayToInt(dataRow->lstIdxGet, TEXT("/"), idx);
	tmp.lstValGet = getArrayToInt(dataRow->lstValGet, TEXT("/"), idx);

	return tmp;
}

FEvolutionInfoData AplyctrMaingame::LoadEvolInfo(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EvolInfoData.EvolInfoData'")));
	FEvolutionInfoTable* dataRow = tblObject->FindRow<FEvolutionInfoTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	FEvolutionInfoData tmp = FEvolutionInfoData();

	tmp.sprite = LoadObject<UPaperSprite>(UPaperSprite::StaticClass(), *LoadEvolSprite(dataRow->idxIcon));
	tmp.strNAme = dataRow->strNAme;
	tmp.strInfo = dataRow->strInfo;

	return tmp;
}

FChallengeInfoData AplyctrMaingame::LoadChallengeInfo(int lvl, int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/ChallengeInfoData.ChallengeInfoData'")));
	FChallengeInfoTable* dataRow = tblObject->FindRow<FChallengeInfoTable>(*FString::Printf(TEXT("%d"), (lvl * 10) + idx), TEXT("DATA"));

	FChallengeInfoData tmp = FChallengeInfoData();

	TArray<FString> lstIdx = getArray(dataRow->idxReward, "/");
	for (int i = 0; i < lstIdx.Num(); i++)
		tmp.idxReward.Add(FCString::Atoi(*lstIdx[i]));

	TArray<FString> lstval = getArray(dataRow->valReward, "/");
	for (int i = 0; i < lstval.Num(); i++)
		tmp.valReward.Add(FCString::Atoi(*lstval[i]));

	return tmp;
}

int AplyctrMaingame::LoadGameLevelData(int lvl)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/GameLevelData.GameLevelData'")));
	FGameLevelTable* dataRow = tblObject->FindRow<FGameLevelTable>(*FString::Printf(TEXT("%d"), lvl), TEXT("DATA"));

	return dataRow->valEXP;
}

float AplyctrMaingame::LoadCameraData(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/CameraData.CameraData'")));
	FCameraTable* dataRow = tblObject->FindRow<FCameraTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->valHeight;
}

TArray<FString> AplyctrMaingame::getArray(FString str, FString word)
{
	TArray<FString> lst;
	str.ParseIntoArray(lst, *word, true);

	return lst;
}

FString AplyctrMaingame::getArrayToString(FString str, FString word, int idx)
{
	if (str.IsEmpty() == true)
	{
		return TEXT("");
	}

	/** todo : error. check array index */
	TArray<FString> lst = getArray(str, *word);
	if (idx >= lst.Num())
	{
		idx = lst.Num() - 1;
	}

	return lst[idx];
}

int AplyctrMaingame::getArrayToInt(FString str, FString word, int idx)
{
	return FCString::Atoi(*getArrayToString(str, word, idx));
}

float AplyctrMaingame::getArrayToFloat(FString str, FString word, int idx)
{
	return FCString::Atof(*getArrayToString(str, word, idx));
}


FString AplyctrMaingame::LoadMonsterSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/MonsterSpriteData.MonsterSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadEquipSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EquipSpriteData.EquipSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadItemSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/ItemSpriteData.ItemSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadBulletSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/BulletSpriteData.BulletSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadGoodsSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/GoodsSpriteData.GoodsSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadSkillSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/SkillSpriteData.SkillSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

FString AplyctrMaingame::LoadEvolSprite(int idx)
{
	UDataTable* tblObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("/Script/Engine.DataTable'/Game/DATA/EvolSpriteData.EvolSpriteData'")));
	FSpriteTable* dataRow = tblObject->FindRow<FSpriteTable>(*FString::Printf(TEXT("%d"), idx), TEXT("DATA"));

	return dataRow->strPath;
}

AActor* AplyctrMaingame::CreateEffect(FString cls, FVector2D loc, float zoom)
{
	UClass* CharactorClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *cls));

	FActorSpawnParameters spawn;
	spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* aaa = GetWorld()->SpawnActor<AActor>(CharactorClass, FVector(0, 0, 500), FRotator(0, 0, 90), spawn);

	aaa->SetActorLocation(FVector(loc.X, loc.Y, 1.5f));
	aaa->SetActorScale3D(FVector(zoom));

	return aaa;
}

AcharBase* AplyctrMaingame::CreateCharacter(FString cls, int spr, FVector2D loc, float zoom)
{
	UClass* CharactorClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *cls));

	FActorSpawnParameters spawn;
	spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AcharBase* aaa = GetWorld()->SpawnActor<AcharBase>(CharactorClass, FVector(0, 0, 500), FRotator(0), spawn);

	aaa->SetActorLocation(FVector(loc.X, loc.Y, 1.5f));
	aaa->sprChar->SetWorldScale3D(FVector(zoom));

	return aaa;
}


AcharMonster* AplyctrMaingame::CreateMonster(int idx, FVector2D loc, TEnumAsByte<EMonsterSection::Type> sec)
{
	FMonsterData data = LoadMonsterData(idx);
	AcharMonster* tmp = nullptr;

	float valScale = 1.0f;

	switch (sec)
	{
	case EMonsterSection::ITEM:
		UE_LOG(LogTemp, Warning, TEXT("Item box"));
		valScale = 0.1f;
		break;
	case EMonsterSection::MONSTER:
		valScale = 0.1f;
		break;
	case EMonsterSection::CHAMPION:
		valScale = 0.18f;
		break;
	case EMonsterSection::BOSS:
		valScale = 0.2f;
		break;
	}

	tmp = (AcharMonster*)CreateCharacter(TEXT("/Script/CoreUObject.Class'/Script/TIDALFALTS.charMonster'"), data.idxSpr, loc, valScale);
	tmp->setSprite(LoadMonsterSprite(idx));

	tmp->idxMonster = idx;
	tmp->secMonster = sec;
	tmp->spdMove = data.spdMove;
	tmp->valHPMax = data.valHP;
	tmp->valPower = data.valPower;

	tmp->secMove = data.secMove;

	tmp->secDefAttack = data.secDefAttack;
	tmp->idxDefAttack = data.idxDefAttack;
	tmp->timDefAtkMax = data.timDefAttack;
	tmp->timDefAtkNow = 0;


	return tmp;
}


AcharHero* AplyctrMaingame::CreateHero(int idx, FVector2D loc)
{
	AcharHero* tmp = nullptr;


	tmp = (AcharHero*)CreateCharacter(TEXT("/Script/Engine.Blueprint'/Game/BP/charHeroBP.charHeroBP_C'"), 0, loc, 0.1f);
	//tmp->setSprite(TEXT("/Script/Paper2D.PaperFlipbook'/Game/CHAR/Hero/sprHero1.sprHero1'"));

	tmp->valHPNow = 100;

	return tmp;
}

AcharOption* AplyctrMaingame::CreateOption(FVector2D loc)
{
	AcharOption* tmp = nullptr;

	tmp = (AcharOption*)CreateCharacter(TEXT("/Script/Engine.Blueprint'/Game/BP/charOptionBP.charOptionBP_C'"), 0, loc, 0.1f);

	return tmp;
}


AactBullet* AplyctrMaingame::CreateBullet(int idx, FVector2D loc)
{
	FBulletData data = LoadBulletData(idx);

	UClass* BulletClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *data.strPath));

	FActorSpawnParameters spawn;
	spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AactBullet* tmp = GetWorld()->SpawnActor<AactBullet>(BulletClass, FVector(0, 0, 500), FRotator(0), spawn);
	tmp->SetActorLocation(FVector(loc.X, loc.Y, 1.5f));

	tmp->idxBullet = idx;
	tmp->timProc = 0;

	return tmp;
}

AactItem* AplyctrMaingame::CreateGoods(int idx, FVector2D loc)
{
	UClass* ItemClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, TEXT("/Script/CoreUObject.Class'/Script/TIDALFALTS.actItem'")));

	FActorSpawnParameters spawn;
	spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AactItem* tmp = GetWorld()->SpawnActor<AactItem>(ItemClass, FVector(0, 0, 500), FRotator(0), spawn);
	tmp->SetActorLocation(FVector(loc.X, loc.Y, 1.5f));
	tmp->sprItem->SetWorldScale3D(FVector(0.1f));

	FGoodsData data = LoadGoodsData(idx);
	tmp->setSprite(LoadGoodsSprite(data.idxSpr));

	tmp->valShame = data.valShame;
	tmp->secGoods = data.secGoods;

	tmp->SetActorScale3D(FVector(1.0f));

	return tmp;
}


FRotator AplyctrMaingame::GetDistRotator(FVector posFrom, FVector posTarget)
{
	return UKismetMathLibrary::FindLookAtRotation(posFrom, posTarget);
}

FVector AplyctrMaingame::GetForwardVector(FRotator InRot)
{
	return FRotationMatrix(InRot).GetScaledAxis(EAxis::X);
}

FVector2D AplyctrMaingame::Get2DFrom3D(FVector WorldPosition)
{
	ULocalPlayer* LocalPlayer = GEngine->GetGamePlayer(GEngine->GameViewport, 0);
	FVector2D MyResult;

	if (LocalPlayer != NULL && LocalPlayer->ViewportClient != NULL && LocalPlayer->ViewportClient->Viewport != NULL)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, /*out*/ ViewLocation, /*out*/ ViewRotation, LocalPlayer->ViewportClient->Viewport);

		if (SceneView)
		{
			//			auto MyWorldPosition = FVector(WorldPosition);
			//			FVector2D MyResult;
			SceneView->WorldToPixel(WorldPosition, MyResult);
		}
	}

	return MyResult;
}
