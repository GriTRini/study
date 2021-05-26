#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {

private:
	int up;
	int dw;
	
public:
	Rational(int up, int dw);
	Rational(int up);
	~Rational();

	int upper();
	int down();

	void upper(int up);
	void down(int dw);

};

#endif
