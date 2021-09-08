// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	//UE_LOG(LogTemp, Warning, TEXT("A Pawn was killed"));

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());

	if (Cast<APlayerController>(PawnKilled->GetController()) != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("1"));

	if(PawnKilled->GetController() != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("2"));

	if (PlayerController != nullptr)
	{
		EndGame(false);
	}


	//For loop over all ShooterAI in the world
		//Is not Dead?
			//return 

	// If loop ends and no early returns ENd Game 

	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead())
		{
			return;
		}
	}

	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}