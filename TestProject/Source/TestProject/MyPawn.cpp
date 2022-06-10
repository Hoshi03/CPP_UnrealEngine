// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/FloatingPawnMovement.h"
#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));


	//규칙 - 컴포넌트를 만들땐 하나를 루트 컴포넌트로 추가하기
	RootComponent = Mesh;

	//메쉬 타입을 SM_Couch로 고정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));
	//성공했으면
	if (SM.Succeeded()) {
		//메쉬를 스태틱으로 고정시켜줌
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//언리얼은 키 입력 받는 부분을 따로 떼어서 관리함
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//축을 따라서 입력 받음
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
}

void AMyPawn::UpDown(float Value) {
	if (Value == 0.f)
		return;
	//입력 받은방향으로 로그 찍어줌
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);

	//입력 방향으로 이동!
	AddMovementInput(GetActorForwardVector(), Value);

}

void AMyPawn::LeftRight(float Value) {
	if (Value == 0.f)
		return;
	//입력 받은방향으로 로그 찍어줌
	UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
	AddMovementInput(GetActorRightVector(), Value);

}
