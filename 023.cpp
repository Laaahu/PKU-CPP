/*
023:Fun和Do

总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空输出指定结果

输入
无
输出
A::Fun
C::Do
样例输入
None
样例输出
A::Fun 
C::Do 
*/

#include <iostream> 
using namespace std;
class A { 
	private: 
	int nVal; 
	public: 
	void Fun() 
	{ cout << "A::Fun" << endl; }; 
	void Do() 
	{ cout << "A::Do" << endl; } 
}; 
class B:public A { 
	public: 
	virtual void Do() 
	{ cout << "B::Do" << endl;} 
}; 
class C:public B { 
	public: 
	void Do( ) 
	{ cout <<"C::Do"<<endl; } 
	void Fun() 
	{ cout << "C::Fun" << endl; } 
}; 
void Call(
// 在此处补充你的代码
B &p    //通过基类的引用调用基类和派生类中同名、同参数表的虚函数时，若引用的是一个基类的对象，则被调用的是基类的虚函数，若被引用的是一个派生类的对象，则被调用的是派生类的虚函数
) { 
	p.Fun(); p.Do(); 
} 
int main() { 
	C c; 
	Call( c); 
	return 0;
}