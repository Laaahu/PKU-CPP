/*
029:简单的Filter
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写Filter模板，使得程序产生指定输出 不得编写 Filter函数

输入
无
输出
MikeJackLucy
3,4,5,
样例输入
无
样例输出
MikeJackLucy
3,4,5,
*/

#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template<class T1, class T2>
T1 Filter(T1 b, T1 e, T1 tb, T2 fun) {
    while (b != e) 
    {
        if (fun(*b)) {
            *tb = *b;
            tb++;
        }
        b++;
    }
    
    return tb;
}
bool LargerThan2(int n)
{
	return n > 2;
}
bool LongerThan3(string s) 
{
	return s.length() > 3;
}

string as1[5] = {"Tom","Mike","Jack","Ted","Lucy"};
string as2[5];
int  a1[5] = { 1,2,3,4,5};
int a2[5];
int main() {
	string * p = Filter(as1,as1+5,as2,LongerThan3);
	for(int i = 0;i < p - as2; ++i)
		cout << as2[i];
	cout << endl; 
	int * p2 = Filter(a1,a1+5,a2,LargerThan2);
	for(int i = 0;i < p2-a2; ++i)
		cout << a2[i] << ",";
	return 0;
}
