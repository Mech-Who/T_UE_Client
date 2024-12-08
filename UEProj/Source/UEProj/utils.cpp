#include "utils.h"

void Utils::display(FString msg)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, msg);
	}
}

void Utils::display_log(FString msg)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *msg);
	display(msg);
}

void Utils::display_error(FString msg)
{
	UE_LOG(LogTemp, Error, TEXT("%s"), *msg);
	display(msg);
}

void Utils::display_warning(FString msg)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *msg);
	display(msg);
}

void Utils::display_display(FString msg)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *msg);
	display(msg);
}
