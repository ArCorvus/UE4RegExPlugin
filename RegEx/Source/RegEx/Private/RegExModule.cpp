// Copyright 2014-2016 2Scars Games, Inc. All Rights Reserved.

#include "RegExPrivatePCH.h"


class FRegEx : public IRegEx
{
private:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FRegEx, RegEx )



void FRegEx::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FRegEx::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



