/*
009:哪来的输出

描述
程序填空，输出指定结果

输入
无
输出
2
1
*/

#include <iostream>
using namespace std;
class A {
	public:
		int i;
		A(int x) { i = x; }
// 在此处补充你的代码
    ~A() {
        cout << i << endl;
    }
};
int main()
{
	A a(1);
	A * pa = new A(2);
	delete pa;
	return 0;
}