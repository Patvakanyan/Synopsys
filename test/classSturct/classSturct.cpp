#include<iostream>

class A{
	private:
	int a;
	int b;
	public:
		A():a(0), b(0)
		{
		}
		int get_a(){
			return a;
		}
};

struct AA
{
	int a;
	int b;
	AA():a(0), b(0){}
	int get_a(){return a;}
};

int main()
{
	A a;
	AA aa;


	std::cout<<"get_a = "<< a.get_a()<<std::endl;
	std::cout<<"get_aa = "<< aa.get_a()<<std::endl;
	std::cout<<"a = "<< sizeof(a)<<"\n"<<"aa = "<< sizeof(aa)<<std::endl; 
}
