// Copyright 2014-2016 2Scars Games, Inc. All Rights Reserved.

#pragma once

#include "RegExFunctionLibrary.generated.h"

UCLASS(MinimalAPI)
class URegExFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	/**
	* Returns true if passed regular expression (pattern) is valid
	*
	* @param Regex			(in) Regular expression (pattern) to check
	* @param ResultError	(out) Error text if RegEx (pattern) is not valid
	*/
	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static bool RegExIsValid(const FString &Regex, FString &ResultError);

	/**
	* Returns true if passed source string match regular expression (pattern)
	*
	* @param SourceString	(in) String to check
	* @param Regex			(in) Regular expression (pattern)
	* @param IsValid		(out) False if RegEx (pattern) is not valid
	*/
	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static bool RegExMatch(const FString &SourceString, const FString &Regex, bool &IsValid);

	/**
	* Returns new string that made from SourceString with replaces corresponding to pattern
	*
	* @param SourceString	(in) Source String 
	* @param Regex			(in) Regular expression (pattern) of substring that should be replaced
	* @param Replacement	(in) A string with the replacement for each match. ($n - n-th backreference, $&	- entire match, $` - prefix, $´ - suffix, $$)
	* @param IsValid		(out) False if RegEx (pattern) is not valid
	*/
	UFUNCTION(BlueprintCallable, Category="Utilities|String|RegEx")
	static FString RegExReplace(const FString &SourceString, const FString &Regex, const FString &Replacement, bool &IsValid);
};
