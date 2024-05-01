/*
006:奇怪的类复制

描述
程序填空，使其输出9 22 5
*/

#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
    Sample() {}

    Sample(int vv) {
        v = vv;
    }

    Sample(const Sample &s) {
        v = s.v + 2;
    }
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
    cout << a.v << endl;    // 5
	Sample b = a;
    cout << b.v << endl;    // 7
	PrintAndDouble(b); //b会创建一次临时变量、会调用一次复制构造函数
	Sample c = 20;
	PrintAndDouble(c);  //c会创建一次临时变量、会调用一次复制构造函数
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}