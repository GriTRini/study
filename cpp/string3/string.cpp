#include "string.h"
#include <cassert>
#include <cstring>

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	return out << rhs.c_str(); 
}

String::String(const char *str, bool)  //overloading이 안되서 bool 사용
: rep_(new StringRep(str, true))   
{
	assert(this->rep_);
	rep_->rc_= 1;

}

String::String()
: rep_(new StringRep)
{
	assert(this->rep_);
	rep_->rc_=1;
}

String::String(const char *str)
: rep_(new StringRep(str))
{
	assert(this->rep_);
	rep_->rc_= 1;

}

String::String(const String& rhs)
: rep_(rhs.rep_)
{
	++rep_->rc_;
}

String::~String()
{
	--rep_->rc_;
	if (rep_-> rc_ == 0) {
		delete rep_;
	}
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs) {
		--rep_->rc_;
		if (rep_-> rc_ == 0) {
		delete rep_;
		}

		rep_ = rhs.rep_;
		++rep_ -> rc_;
	}

	return *this;
}
	
bool String::operator==(const String& rhs) const
{
	return strcmp(rep_->str_, rhs.rep_->str_) == 0;
}

const String String::operator+(const String& rhs) const
{
	char* tmp = new char[rep_->len_+ rhs.rep_->len_ + 1];
	strcpy(tmp, rep_->str_);
	strcat(tmp, rhs.rep_->str_);

	String result(tmp);
	delete [] tmp;

	return result;
}

const char* String::c_str() const
{
	return const_cast<const char *> (rep_->str_);
}
	
int String::length() const
{
	return rep_->len_;
}