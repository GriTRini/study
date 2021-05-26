class Empty{

public:
	//Empty() { };  // 생성자가 없으면 빈칸인 생성자를 만듦 
	//Empty(const Empty& rhs) { 모든 멤버를 복사}
	//~Empty() { }; // 소멸자가 없으면 빈간인 소멸자를 만듦 
	
	//Empty& operator=(const Empty& rhs) 각각의 모든 멤버를 치환하는 것을 만듦 
	//Empty *operator&() { return this;}
	//const Empty *operator&() const {return this; }
};

int main()
{

	Empty e1;
	Empty e2 = e1;
	
	e2 = e1;
	
	Empty *pe = &e1;
	
	const Empty e3;
	const Empty *pe2 = &e3;

	return 0;
}
