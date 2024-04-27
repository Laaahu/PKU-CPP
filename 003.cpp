/*
003:好怪异的返回值

描述
填空，使得程序输出指定结果
10

主要考察函数的返回值为引用时可以作为左值。
*/
#include <iostream>
using namespace std;
// 在此处补充你的代码
int& getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}