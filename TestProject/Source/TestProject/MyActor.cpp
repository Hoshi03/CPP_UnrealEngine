// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//이름이 MESH인 메쉬 만들어줌, 스마트 포인터처럼 사용
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));

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
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

