// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ONLINE_RPG_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	/** ������Ƽ ���ø����̼� */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** �ִ� ü�� ����*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	/** ���� ü�� ����*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	/** ���� ü�� ����. ���� 0�� MaxHealth ���̷� ���������ϰ� OnHealthUpdate�� ȣ���մϴ�. ���������� ȣ��Ǿ�� �մϴ�.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float healthValue);

	/** �������?�޴� �̺�Ʈ. APawn���� �������̵�˴ϴ�?*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	//���� ���� ����
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool GetIsDead() const { return bIsDead; }
	//���� ���� ����
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetIsDead(bool IsDead);

	void SetIsDead();


	//Shoot ���� ����
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE bool GetIsShoot() const { return bIsShoot; }
	//Shoot ���� ����
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetIsShoot(bool IsShoot);

	//Sword Ŭ����
	UPROPERTY(EditAnywhere, Category = "State")
	TSubclassOf<class ASword> SwordClass;
	UPROPERTY(EditAnywhere, Category = "State")
	ASword* MySword;
	
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** �÷��̾��� �ִ� ü��. ü���� �ִ��Դϴ�. �� ���� ���� �� ���۵Ǵ� ĳ������ ü�� ���Դϴ�.*/
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

	/** �÷��̾��� ���� ü��. 0�� �Ǹ� ���� ������ ���ֵ˴ϴ�.*/
	UPROPERTY(VisibleAnywhere,ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth;

	/** ���� ü�¿� ������ ���濡 ���� RepNotify*/
	UFUNCTION()
	void OnRep_CurrentHealth();

	/** ������Ʈ�Ǵ� ü�¿� ����. ���������� ���� ���?ȣ��, Ŭ���̾�Ʈ������ RepNotify�� �����Ͽ� ȣ��*/
	void OnHealthUpdate();


	UPROPERTY(EditDefaultsOnly, Category = "Gameplay|Projectile")
	TSubclassOf<class AProjectile_dm> ProjectileClass;

	/** �߻� �����? ������ ��. �׽�Ʈ �߻�ü�� �߻� �ӵ��� �����ϴ� �� ��������, ���� �Լ��� �߰����� SpawnProjectile�� �Է¿� ���� ���ε����� �ʰ� �ϴ� ���ҵ� �մϴ�.*/
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float FireRate;

	/** true�� ���?�߻�ü�� �߻��ϴ� ���μ��� �����Դϴ�. */
	bool bIsFiringWeapon;

	/** ���� �߻� ���� �Լ�*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StartFire();

	/** ���� �߻� ���� �Լ�. ȣ��Ǹ�?�÷��̾ StartFire�� �ٽ� �����?�� �ֽ��ϴ�.*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StopFire();

	/** �߻�ü�� �����ϴ� ���� �Լ�*/
	UFUNCTION(Server, Reliable)
	void HandleFire();

	/** ���� ���̿� �߻� �ӵ� ����̸�?�ִ� Ÿ�̸� �ڵ�*/
	FTimerHandle FiringTimer;


	/** ���� ��Ÿ��*/
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float AttackRate;

	/** true�� ��Ÿ�� */
	bool bIsAttackWeapon;

	/** ����*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StartAttack();

	/** ���� ��Ÿ�� ��*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StopAttack();

	/** ���� �����Լ�*/
	UFUNCTION(Server, Reliable)
	void HandleAttack();

	/** ���� ��Ÿ�ӿ� Ÿ�̸� �ڵ�*/
	FTimerHandle AttackTimer;

	//���� Attack ����
	bool bIsAttack;


	UPROPERTY(VisibleAnywhere, Category = "State")
	bool bIsFalling;

	//���� ���� ����
	UPROPERTY(ReplicatedUsing = OnRep_IsDead)
	bool bIsDead;

	//���� ���� ���濡 ���� RepNotify
	UFUNCTION()
	void OnRep_IsDead();

	//������Ʈ�Ǵ� ���� ���¿� ����. ���������� ���� ��� ȣ��, Ŭ���̾�Ʈ������ RepNotify�� �����Ͽ� ȣ��
	void OnIsDeadUpdate();

	//���� Shoot ����
	bool bIsShoot;

	//���۽�����
	UPROPERTY(ReplicatedUsing=OnRep_IsUpperSlash)
	bool bIsUpperSlash;
	float UpperSlash_Rate = 2.0f;

	UFUNCTION()
	void StopUpperSlash();

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool GetIsUpperSlash() const;

	UFUNCTION()
	void OnRep_IsUpperSlash();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* FireAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* UpperSlashAction;

protected:
	void Move(const struct FInputActionInstance& Instance);
	void Look(const FInputActionInstance& Instance);
	void UpperSlash();

private:
	//?�시
	void SpawnDebugSphere(FVector Location, float Radius);
	void CMAttack();
	UPROPERTY(EditAnywhere, Category = "Attack")
	float CMAttackRange = 1000.f;
	UPROPERTY(EditAnywhere, Category = "Attack")
	float CMAttackDamage = 5.f;

};
