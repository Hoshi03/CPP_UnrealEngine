// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

//언리얼에서 사용하는 리플렉션 기능
UCLASS()
//네이밍 컨벤션 따라서 A를 하나 더 붙여줌 
class TESTPROJECT_API AMyActor : public AActor
{
	//언리얼 클래스임을 컴파일러가 알 게 하는 느낌?
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	//언리얼에서 관리하는 메모리라는 걸 알려주고 안에 vis~~로 속성을 건들 수 있게 함
	UPROPERTY(VisibleAnywhere)
	//스태틱 매쉬
	UStaticMeshComponent* Mesh;

	//EditAnywhere - 언리얼 상에서 생성한 변수인 hp를 수정가능하게 만들어줌, 카테고리 설정하면 카테고리 안에 변수가 들어가있음
	UPROPERTY(EditAnywhere, Category = Status)
	int32 hp;

	UPROPERTY(EditAnywhere)
	int32 mp;

	UPROPERTY(EditAnywhere, Category = BattleStatus)
	float  rotatespeed = 30.f;

};
