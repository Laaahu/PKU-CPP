/*
012:这个指针哪来的

描述
填空，按要求输出

输入
无
输出
10
样例输入
无
样例输出
10
*/

#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
// 在此处补充你的代码
    const A* getPointer() const {
        const A *p = this;
        return p;
    }
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}