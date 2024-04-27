/*
004:神秘的数组初始化

描述
填空，使得程序输出指定结果
123,456

主要考察new 返回为指针，以及初始化指针数组
*/

#include <iostream>
using namespace std;

int main()
{
	int * a[] = {
// 在此处补充你的代码
NULL, NULL, new int, new int[6]
};
	
	*a[2] = 123;
	a[3][5] = 456;
	if(! a[0] ) {
		cout << * a[2] << "," << a[3][5];
	}
	return 0;
}