#include "complex.h"

std::istream& operator >>(std::istream& in, Complex& rhs)
{
   double re = 0.0;
   double im = 0.0;
   
   char c = 0;
   in >> c;
   if(c == '(') {
      in >> re >> c;
      if(c == ',')
         in >> im >> c;
      if(c == 'i')
         in >> c;
      if(c == ')')
         in.clear(std::ios::failbit);
   
   } else{
      in.putback(c);
      in >> re;
   }
   
   if(in)
      rhs = Complex(re, im);
      
   return in;
}

std::ostream& operator << (std::ostream& out, const Complex& rhs){
   out << "(" << rhs.re << ", " << rhs.im << "i)";
   
   return out;
}
Complex::Complex(double re, double im){
   this->re = re;
   this->im = im;
}

Complex::Complex(const Complex& rhs){
   this->re = rhs.re;
   this->im = rhs.im;
}

Complex::~Complex(){

}

Complex& Complex::operator=(const Complex& rhs){
   this->re=rhs.re;
   this->im=rhs.im;
   
   return *this;
}

Complex& Complex::operator=(double re){
   this->re = re;
   
   return *this;
}

bool Complex::operator == (const Complex& rhs) const{
   return (this->re == rhs.re && this->im== rhs.im);
}

bool Complex::operator != (const Complex& rhs) const{
   return (this->re != rhs.re || this->im != rhs.im);
}

const Complex Complex::operator+(const Complex& rhs) const{
   return Complex(this->re + rhs.re, this->im + rhs.im);
}

Complex& Complex::operator++(){
   this->re += 1.0;
   
   return *this;
}

Complex Complex::operator++(int ){
   Complex tmp(*this);
   this->re += 1.0;
   
   return tmp;
}

double Complex::real() const{
   return this->re;
}

double Complex::imag() const{
   return this->im;
}

void Complex::real(double re){
   this->re=re;
}

void Complex::imag(double im){
   this->im=im;
}