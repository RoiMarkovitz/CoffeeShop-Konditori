#include "StringUtil.h"
#include <String.h>
#include <ctype.h>

// is only letters and spaces
bool StringUtil::isValidName(const char* str)
{
	int length;

	if (isEmptyOrNull(str)) // cannot be empty or null
		return false;
	
	if (str[0] == ' ') // cannot start with a space
		return false;
	
	length = (int)strlen(str);

	for (int i = 0; i < length; i++) {
		if (!isalpha(str[i]) && str[i] != ' ') { // must be a letter or a space
			return false;
		}
	}
	return true;
}

bool StringUtil::isEmptyOrNull(const char* str) 
{
	return str == nullptr || strlen(str) == 0;
}




