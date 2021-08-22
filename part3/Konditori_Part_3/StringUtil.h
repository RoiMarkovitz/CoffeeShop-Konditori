#ifndef __STRINGUTIL_H
#define __STRINGUTIL_H

class StringUtil
{
private:
	StringUtil();
public:
	static bool isValidName(const char* str);
	static bool isEmptyOrNull(const char* str);
};


#endif // __STRINGUTIL_H


