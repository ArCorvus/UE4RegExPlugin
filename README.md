# UE4RegExPlugin
Plugin that adds Regular expressions to blueprints in Unreal Engine 4

**Plugin is not complete yet and not stable!**

There is a **crash on Shipping** when regular expression is incorrect.

Plugin adds blocks to blueprints:
* RegExIsValid(String Regex) -> bool ResultValue, String ResultError
* RegExMatch(String SourceString, String Regex) -> bool ResultValue, bool isValid
* RegExReplace(String SourceString, String Regex, String Replacement) -> String ResultValue, bool isValid
