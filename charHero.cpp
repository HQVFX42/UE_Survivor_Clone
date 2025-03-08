#include "charHero.h"
#include "plyctrMaingame.h"

AcharHero::AcharHero()
{
	renderSpine = CreateDefaultSubobject<USpineSkeletonRendererComponent>(TEXT("renderSpine"));
	renderSpine->SetupAttachment(RootComponent);
	renderSpine->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));
	renderSpine->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	renderSpine->SetRelativeScale3D(renderSpine->GetComponentScale() * 0.5f);

	animSpine = CreateDefaultSubobject<USpineSkeletonAnimationComponent>(TEXT("animSpine"));

	secChar = ECharSection::Hero;
}

void AcharHero::BeginPlay()
{
	Super::BeginPlay();

	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	SetAnim(EAnimHero::IDLE);

	animSpine->SetAnimation(1, FString("wind-mild"), true);

	plyOpt = PC->CreateOption(FVector2D(GetActorLocation().X - 30.f, GetActorLocation().Y - 5.f));
}

void AcharHero::Tick(float DeltaTime)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	Super::Tick(DeltaTime);

	renderSpine->SetRelativeRotation(FRotator(0, GetActorRotation().Yaw * -1, -90.f));

	plyOpt->SetActorLocation(FVector(GetActorLocation().X - 30.f, GetActorLocation().Y - 5.f, GetActorLocation().Z));


	if (PC->chrPlayer->secNow != ESecSection::Battle)
		return;

	switch (PC->chrPlayer->secNow)
	{
	case ESecSection::Battle:
		procWeapon(DeltaTime);
		procRecover(DeltaTime);
		break;
	}


}

float AcharHero::getMaxHP()
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	float hp = valHPMax;

	if (PC->chrPlayer->playData.lvlSubBuff[2] >= 0)
		hp += (hp * PC->LoadBuffData(2, PC->chrPlayer->playData.lvlSubBuff[2]).valLevel * PC->chrPlayer->playData.lvlSubBuff[2]);

	return hp;
}


float AcharHero::calAttack()
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	float dmg = valPower;

	if (PC->chrPlayer->playData.lvlSubBuff[4] >= 0)
		dmg += (dmg * PC->LoadBuffData(4, PC->chrPlayer->playData.lvlSubBuff[4]).valLevel * PC->chrPlayer->playData.lvlSubBuff[4]);

	return dmg;
}

float AcharHero::calDefence(float dmg)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	float val = dmg;

	return val;
}

void AcharHero::addDamage(float dmg)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	if (PC->chrPlayer->secNow == ESecSection::Waiting)
		return;

	if (PC->chrPlayer->playData.timIronman > 0)
		return;

	float val = calDefence(dmg);

	ChangeHP(val * -1, getMaxHP());

	if (valHPNow <= 0)
		setDie();
}

void AcharHero::setDie()
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	SetAnim(EAnimHero::DIE);

	if (PC->chrPlayer->playData.isReborn)
		PC->chrPlayer->showReborn = true;
	else
		PC->chrPlayer->showResult = true;

	PC->chrPlayer->secNow = ESecSection::Waiting;
}

void AcharHero::procRecover(float time)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));


	if (PC->chrPlayer->playData.lvlSubBuff[5] >= 0)
	{
		PC->chrPlayer->playData.timRecover += time;

		if (PC->chrPlayer->playData.timRecover >= 5.0f)
		{
			PC->chrPlayer->playData.timRecover -= 5.0f;

			ChangeHP(getMaxHP() * PC->LoadBuffData(5, PC->chrPlayer->playData.lvlSubBuff[5]).valLevel * PC->chrPlayer->playData.lvlSubBuff[5], getMaxHP());
		}
	}
}

void AcharHero::procWeapon(float time)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	for (int v = 0; v < 2; v++)
	{
		int idx = -1;
		int max = 1;

		if (v == WEAPON_MAIN)
			idx = PC->chrPlayer->getHeroWeaponIndex();
		else
			max = SKILL_WEAPON_TYPE;

		for (int z = 0; z < max; z++)
		{
			if (v == WEAPON_SUB)
			{
				idx = z;

				if (PC->chrPlayer->playData.lvlSubWeapon[idx] < 0)
					continue;
			}

			bool isRun = true;

			FWeaponData data;

			int lvl = 0;

			if (v == WEAPON_MAIN)
			{
				lvl = PC->chrPlayer->playData.lvlMainWeapon;
			}
			else
			{
				if (PC->chrPlayer->playData.lvlSubWeapon[idx] >= 0)
					lvl = PC->chrPlayer->playData.lvlSubWeapon[idx];
				else
					isRun = false;
			}

			data = PC->LoadWeaponData(v, idx, lvl);

			if (isRun)
			{
				float realtime = data.timAttack;

				if (PC->chrPlayer->playData.lvlSubBuff[0] >= 0)
					realtime -= (realtime * (PC->LoadBuffData(0, PC->chrPlayer->playData.lvlSubBuff[0]).valLevel * PC->chrPlayer->playData.lvlSubBuff[0]));

				bool chk = false;

				if (v == WEAPON_MAIN)
				{
					PC->chrPlayer->playData.timMainWeapon += time;

					if (PC->chrPlayer->playData.timMainWeapon >= realtime)
						chk = true;
				}
				else
				{
					PC->chrPlayer->playData.timSubWeapon[idx] += time;

					if (PC->chrPlayer->playData.timSubWeapon[idx] >= realtime)
						chk = true;
				}

				if (chk)
				{
					int dual = setBullet(data);

					if (dual >= 0)
						setBullet(PC->LoadWeaponData(v, dual, lvl));

					if (v == WEAPON_MAIN)
					{
						PC->chrPlayer->playData.timMainWeapon -= realtime;

						if (data.secAttack < EWaeaponAttackSection::CIRCLE)
							animSpine->SetAnimation(2, FString("attack-shot"), false);
						else if (data.secAttack == EWaeaponAttackSection::CIRCLE)
							animSpine->SetAnimation(2, FString("attack-angle"), false);
						else
							animSpine->SetAnimation(2, FString("attack-slash"), false);
					}
					else
					{
						PC->chrPlayer->playData.timSubWeapon[idx] -= realtime;
					}
				}
			}
		}
	}
}

int AcharHero::setBullet(FWeaponData data)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	FVector locForward = FVector(0);

	if (data.secAttack == EWaeaponAttackSection::SHOT_AUTO)
	{
		float gap = 100000.f;
		int target = -1;

		TArray<AActor*> lstMonster;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AcharMonster::StaticClass(), lstMonster);

		for (int i = 0; i < lstMonster.Num(); i++)
		{
			float chk = FVector::Dist(lstMonster[i]->GetActorLocation(), GetActorLocation());

			if (chk < gap)
			{
				gap = chk;
				target = i;
			}
		}

		if (target >= 0)
			locForward = PC->GetForwardVector(PC->GetDistRotator(GetActorLocation(), lstMonster[target]->GetActorLocation()));
		else
			locForward = PC->GetForwardVector(FRotator(0, FMath::RandRange(0, 11) * 15.f, 0));
	}
	else
	{
		locForward = GetActorForwardVector();
	}

	for (int i = 0; i < data.bulSame; i++)
	{
		for (int j = 0; j < data.bulCombo; j++)
		{
			FVector locSpwan = GetActorLocation();

			AactBullet* tmp = PC->CreateBullet(data.idxbullet, FVector2D(locSpwan.X, locSpwan.Y));
			tmp->SetActorScale3D(FVector(data.valScale));

			if (data.secAttack == EWaeaponAttackSection::CLUB_LOOK)
			{
				tmp->locPlayer = locForward * 20.f;
				tmp->SetActorLocation(GetActorLocation() + tmp->locPlayer);
				tmp->SetActorRotation(PC->GetDistRotator(GetActorLocation(), GetActorLocation() + tmp->locPlayer) + FRotator(0, 90, 0));
			}

			tmp->secTarget = ETargetSection::MONSTER;
			tmp->timProc = j * data.timCombo * -1;
			tmp->timDestroy = data.timOutMove;

			tmp->valPower = calAttack() * data.perPower;
			tmp->spdMove = data.spdMove;

			if (PC->LoadBulletData(tmp->idxBullet).secDamage == EBulletDamageSection::NONE)
				tmp->colSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			if (data.secAttack == EWaeaponAttackSection::RADIAL_LOOK)
			{
				float startRot = data.bulSame * 10.f * -0.4f;

				tmp->locForward = PC->GetForwardVector(GetActorRotation() + FRotator(0, startRot + (i * 10.f), 0));
			}
			else if (data.secAttack == EWaeaponAttackSection::CIRCLE)
			{
				float gap = 360.f / data.bulSame;

				tmp->rotMove = i * gap;
			}
			else if (data.secAttack == EWaeaponAttackSection::RANDOM)
			{
				TArray<AActor*> lstMonster;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), AcharMonster::StaticClass(), lstMonster);

				if (lstMonster.Num() > 0)
				{
					FVector loc = lstMonster[FMath::RandRange(0, lstMonster.Num() - 1)]->GetActorLocation();

					tmp->SetActorLocation(loc - FVector(0, 800, 0));
					tmp->locForward = PC->GetForwardVector(PC->GetDistRotator(tmp->GetActorLocation(), loc));;
				}
			}
			else
			{
				tmp->locForward = locForward;
			}

			tmp->colSphere->SetGenerateOverlapEvents(true);
		}
	}

	return data.idxDual;
}

void AcharHero::SetAnim(TEnumAsByte<EAnimHero::Type> anim)
{
	switch (anim)
	{
	case EAnimHero::IDLE:
		if (animChar != EAnimHero::IDLE)
		{
			if (animChar != EAnimHero::DIE)
			{
				animSpine->SetAnimation(0, FString("idle"), true);
				plyOpt->SetAnim(EAnimOption::IDLE);
			}
		}
		break;

	case EAnimHero::MOVE:
		if (animChar != EAnimHero::MOVE)
		{
			if (animChar != EAnimHero::DIE)
			{
				animSpine->SetAnimation(0, FString("run"), true);
				plyOpt->SetAnim(EAnimOption::MOVE);
			}
		}
		break;

	case EAnimHero::DIE:
		if (animChar != EAnimHero::DIE)
		{
			animSpine->SetAnimation(0, FString("dead"), true);
			plyOpt->SetAnim(EAnimOption::MOVE);
		}
		break;
	}

	animChar = anim;
}

void AcharHero::SetDir(float val)
{
	FVector scale = FVector(0.5f);

	if (val < 0)
	{
		if (dir != 0)
		{
			renderSpine->SetRelativeScale3D(FVector(FMath::Abs(scale.X) * -1, scale.Y, scale.Z));

			plyOpt->renderSpine->SetRelativeScale3D(FVector(FMath::Abs(scale.X) * -1, scale.Y, scale.Z));

			dir = 0;
		}
	}
	else
	{
		if (dir != 1)
		{
			renderSpine->SetRelativeScale3D(FVector(FMath::Abs(scale.X) * 1, scale.Y, scale.Z));

			plyOpt->renderSpine->SetRelativeScale3D(FVector(FMath::Abs(scale.X) * 1, scale.Y, scale.Z));

			dir = 1;
		}
	}

}