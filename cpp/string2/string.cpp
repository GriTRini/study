#include <cstring>
#include <cassert>
#include <iostream>
#include "string.h"

#ifndef INLINE
#define inline
#include "string.inl"
#endif

void String::set_str(const char *str)
{
	if (str ) {
	this->str = new char[strlen(str) + 1];
	assert(this->str );
	strcpy(this->str, str);
	this->len = strlen(str);
	} else {
		this->str = new char[1];
		assert(this->str );
		this->str[0] = '\0';
		this->len = 0;
	}
}
/*
String::String()
{
	this->str = new char[1];
	assert(this->str );
	this->str[0] = '\0';
	this->len = 0;
}
*/



String& String::operator=(const String& rhs)
{
	if (this-> str != str) {				// self assignment test.
		delete [] this->str;
		this->set_str(str);
	}
	return *this;
}
	


const String String::operator+(const String& rhs) const
{
	char *tmp = new char[strlen(this->str) + strlen(rhs.str) + 1];
	assert(tmp);
	strcpy(tmp, this->str);
	strcat(tmp, rhs.str);
	
	String result(tmp, true);
	return result;
}


