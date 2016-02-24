#include "RegExPrivatePCH.h"
#include "RegExFunctionLibrary.h"
#include <regex>


URegExFunctionLibrary::URegExFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

#if _HAS_EXCEPTIONS == 1
#define RE_TRY try {
#define RE_CATCH(x) } catch(x) {
#define RE_CATCH_CODE(x) x
#define RE_CATCH_END }
#else
#define RE_TRY if (1) {
#define RE_CATCH(x) } else if (0) {
#define RE_CATCH_CODE(x)
#define RE_CATCH_END }
#endif

bool getRegExSafety(const FString &reStr, std::basic_regex<TCHAR> *regex = nullptr, FString *errorStr = nullptr)
{
	std::basic_regex<TCHAR> pRegex;
	bool isValid = true;
	RE_TRY
		pRegex = std::basic_regex<TCHAR>(reStr.GetCharArray().GetData());
	RE_CATCH(std::regex_error& e)
		RE_CATCH_CODE( if (errorStr) { *errorStr = e.what(); } )
		isValid = false;
	RE_CATCH_END
	isValid = isValid && (pRegex.flags() > 0);
	if (regex) {
		*regex = pRegex;
	}
	return isValid;
}

bool URegExFunctionLibrary::RegExIsValid(const FString &regex, FString &result)
{
	result = FString();
	std::basic_regex<TCHAR> pRegex;
	return getRegExSafety(regex, nullptr, &result);
}

bool URegExFunctionLibrary::RegExMatch(const FString &sourceString, const FString &regex, bool &isValid)
{
	const TCHAR *pSrcStr = sourceString.GetCharArray().GetData();
	bool res = false;
	std::basic_regex<TCHAR> pRegex;
	isValid = getRegExSafety(regex, &pRegex);
	if (isValid) {
		res = std::regex_match<TCHAR>(pSrcStr, pRegex);
	}
	return res;
}

FString URegExFunctionLibrary::RegExReplace(const FString &sourceString, const FString &regex, const FString &replacement, bool &isValid)
{
	const TCHAR *pSrcStr = sourceString.GetCharArray().GetData();
	FString ueRes;
	std::basic_regex<TCHAR> pRegex;
	isValid = getRegExSafety(regex, &pRegex);
	if (isValid) {
		const TCHAR *pRplcStr = replacement.GetCharArray().GetData();
		std::basic_string<TCHAR> stdRes = std::regex_replace<std::regex_traits<TCHAR>, TCHAR>(pSrcStr, pRegex, pRplcStr);
		ueRes = FString(stdRes.length(), stdRes.c_str());
	}
	return ueRes;
}

