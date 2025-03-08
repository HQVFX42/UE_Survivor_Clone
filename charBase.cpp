#include "charBase.h"
#include "plyctrMaingame.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

AcharBase::AcharBase()
{
	PrimaryActorTick.bCanEverTick = true;

	colSphere = CreateDefaultSubobject<USphereComponent>(TEXT("colSphere"));
	colSphere->InitSphereRadius(12.0f);
	RootComponent = colSphere;

	colSphere->SetCollisionProfileName(TEXT("BlockAll"));
	colSphere->SetSimulatePhysics(true);
	colSphere->SetLinearDamping(10.f);

	sprChar = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("sprChar"));
	sprChar->SetupAttachment(RootComponent);
	sprChar->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));
	sprChar->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AcharBase::BeginPlay()
{
	Super::BeginPlay();
}

void AcharBase::Tick(float DeltaTime)
{
	class AplyctrMaingame* PC = Cast<AplyctrMaingame>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	Super::Tick(DeltaTime);

	SetActorRotation(FRotator(0, GetActorRotation().Yaw, 0));
	sprChar->SetRelativeRotation(FRotator(0, GetActorRotation().Yaw * -1, -90.f));

}

void AcharBase::setSprite(FString path)
{
	sprChar->SetFlipbook(LoadObject<UPaperFlipbook>(UPaperFlipbook::StaticClass(), *path));
}

void AcharBase::ChangeHP(float val, float max)
{
	valHPNow += val;

	if (valHPNow >= max)
		valHPNow = max;

	if (valHPNow < 0)
		valHPNow = 0;
}
