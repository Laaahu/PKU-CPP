/*
002:难一点的swap

描述
填空，使得程序输出结果是：
5,3

主要考察指针变量通过引用来交换
*/

#include <iostream>
using namespace std;

void swap(
// 在此处补充你的代码
int* &a, int* &b
)
{
	int * tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 3,b = 5;
	int * pa = & a;
	int * pb = & b;
	swap(pa,pb);
	cout << *pa << "," << * pb;
	return 0;
}