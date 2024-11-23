#include "utils.h"

void Utils::display(FString msg)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, msg);
	}
}	