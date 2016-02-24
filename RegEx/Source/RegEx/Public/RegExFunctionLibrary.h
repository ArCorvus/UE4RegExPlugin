// Copyright 2014-2016 2Scars Games. All Rights Reserved.

#pragma once

#include "RegExFunctionLibrary.generated.h"

UCLASS(MinimalAPI)
class URegExFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static bool RegExIsValid(const FString &regex, FString &result);

	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static bool RegExMatch(const FString &sourceString, const FString &regex, bool &isValid);

	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static FString RegExReplace(const FString &sourceString, const FString &regex, const FString &replacement, bool &isValid);
};