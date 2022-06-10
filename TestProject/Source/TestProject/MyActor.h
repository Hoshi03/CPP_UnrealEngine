// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

//�𸮾󿡼� ����ϴ� ���÷��� ���
UCLASS()
//���̹� ������ ���� A�� �ϳ� �� �ٿ��� 
class TESTPROJECT_API AMyActor : public AActor
{
	//�𸮾� Ŭ�������� �����Ϸ��� �� �� �ϴ� ����?
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
	//�𸮾󿡼� �����ϴ� �޸𸮶�� �� �˷��ְ� �ȿ� vis~~�� �Ӽ��� �ǵ� �� �ְ� ��
	UPROPERTY(VisibleAnywhere)
	//����ƽ �Ž�
	UStaticMeshComponent* Mesh;

	//EditAnywhere - �𸮾� �󿡼� ������ ������ hp�� ���������ϰ� �������, ī�װ� �����ϸ� ī�װ� �ȿ� ������ ������
	UPROPERTY(EditAnywhere, Category = Status)
	int32 hp;

	UPROPERTY(EditAnywhere)
	int32 mp;

	UPROPERTY(EditAnywhere, Category = BattleStatus)
	float  rotatespeed = 30.f;

};
