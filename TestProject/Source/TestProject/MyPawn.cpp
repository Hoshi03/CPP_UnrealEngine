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


	//��Ģ - ������Ʈ�� ���鶩 �ϳ��� ��Ʈ ������Ʈ�� �߰��ϱ�
	RootComponent = Mesh;

	//�޽� Ÿ���� SM_Couch�� ����
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));
	//����������
	if (SM.Succeeded()) {
		//�޽��� ����ƽ���� ����������
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
//�𸮾��� Ű �Է� �޴� �κ��� ���� ��� ������
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//���� ���� �Է� ����
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);
}

void AMyPawn::UpDown(float Value) {
	if (Value == 0.f)
		return;
	//�Է� ������������ �α� �����
	//UE_LOG(LogTemp, Warning, TEXT("UpDown %f"), Value);

	//�Է� �������� �̵�!
	AddMovementInput(GetActorForwardVector(), Value);

}

void AMyPawn::LeftRight(float Value) {
	if (Value == 0.f)
		return;
	//�Է� ������������ �α� �����
	UE_LOG(LogTemp, Warning, TEXT("LeftRight %f"), Value);
	AddMovementInput(GetActorRightVector(), Value);

}
