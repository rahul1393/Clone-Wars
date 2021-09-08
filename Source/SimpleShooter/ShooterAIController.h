#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DelataSeconds) override;
	bool IsDead() const;
	
private:
	UPROPERTY(EditAnywhere)
		//float AcceptanceRadius = 200;

		class UBehaviorTree* AIBehavior;
};
