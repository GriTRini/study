#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {

private :
	double re;
	double im;
	
public :
	Complex();  
	Complex(double re);
	Complex(double re, double im);
	~Complex();
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double im);
	
	
};

#endif
