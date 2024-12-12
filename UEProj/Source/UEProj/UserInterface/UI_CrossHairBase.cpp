// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_CrossHairBase.h"

#include "Components/Border.h"
#include "Animation/WidgetAnimation.h"

void UUI_CrossHairBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UUI_CrossHairBase::OnFire()
{
	// UE_LOG(LogTemp, Display, TEXT("CrossHair Base On Fire!!"));
	PlayAnimation(ExpandCross, 0, 1,
		EUMGSequencePlayMode::Forward, 2.0f);
}
