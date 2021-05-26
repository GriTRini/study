#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;
	double im;
	
public:
	//Complex();
	//Complex(double re);
	
	Complex(double re = 0.0, double im = 0.0);
	//Complex(const Complex *pc);
	Complex(const Complex& rhs);  // reference // const T type의 reference
	~Complex();
	
	//void operator = (Complex c);			// performance x
	//void operator = (const Complex *pc); 	// c1 = &c3 ???
	
	Complex& operator = (const Complex& rhs);
	
	bool operator == (const Complex& rhs);
	
	const Complex operator+(const Complex& rhs);
	
	
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double im);
	
};

#endif






