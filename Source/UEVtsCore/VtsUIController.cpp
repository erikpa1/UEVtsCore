// Fill out your copyright notice in the Description page of Project Settings.


#include "VtsUIController.h"

#include "Engine.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"




void ListWidgetsInHierarchy(UUserWidget* Widget);

// Sets default values
AVtsUIController::AVtsUIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVtsUIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AVtsUIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVtsUIController::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init called in c++"));

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();


	if (playerController) {
		AHUD* PlayerHud = playerController->GetHUD();
		if (PlayerHud) {

			UE_LOG(LogTemp, Warning, TEXT("Found player hud"));

			
			//UUserWidget* HUDWidget = Cast<UUserWidget>(PlayerHud->GetOwningWidget());

			//if (HUDWidget) {
			//	ListWidgetsInHierarchy(HUDWidget);
			//}

		}
	}



}

void AVtsUIController::TryLogin()
{
	UE_LOG(LogTemp, Warning, TEXT("Trying to log in"));
}


void ListWidgetsInHierarchy(UUserWidget* Widget)
{
	if (!Widget)
		return;


	Widget->GetName();

	// Print or store information about the widget
	UE_LOG(LogTemp, Warning, TEXT("Widget Name: %s"), *Widget->GetName());

	// Traverse child widgets
	TArray<UWidget*> Children;


	Widget->WidgetTree->GetAllWidgets(Children);

	for (UWidget* Child : Children)
	{
		UUserWidget* ChildUserWidget = Cast<UUserWidget>(Child);

		if (ChildUserWidget) {
			ListWidgetsInHierarchy(ChildUserWidget);
		}

	}
}