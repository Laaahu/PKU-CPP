/*
007:返回什么才好呢

描述
程序填空，使其按要求输出

输入
多组数据，每组一行，是整数 m 和 n
输出
先输出一行：
123
然后，对每组数据，输出两行，第一行是m,第二行是n
样例输入
2 3
4 5
样例输出
123
2
3
4
5 
*/

#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int
// 在此处补充你的代码
        v = 123) {
            val = v;
        }

    A& GetObj() {
        return *this;   //返回作用这个函数的对象
    }
};
int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}