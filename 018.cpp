/*
018:别叫，这个大整数已经很简化了!
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果

输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容对应程序中6个输出语句
样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6
样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
*/

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
    char s[210];
public:
    void reverse(char* p) {
        int len = strlen(p);
        int i = 0, j = len - 1;
        while(i < j) {
            swap(p[i], p[j]);
            i++, j--;
        }
    }
    CHugeInt(char* tmp_s) {
        memset(s, 0, sizeof(s));
        strcpy(s, tmp_s);
        reverse(s);
    }
    CHugeInt(int a) {
        memset(s, 0, sizeof(s));
        sprintf(s, "%d", a);
        reverse(s);
    }

    CHugeInt operator + (const CHugeInt& a) {
        CHugeInt tmp(0);
        int carry = 0;
        for(int i = 0; i < 210; i++) {
            char c1 = this -> s[i];
            char c2 = a.s[i];
            if(c1 == 0 && c2 == 0 && carry == 0) break;
            if(c1 == 0) c1 = '0';
            if(c2 == 0) c2 = '0';
            int k = (c1 - '0') + (c2 - '0') + carry;
            if(k > 9) {
                tmp.s[i] = k - 10 + '0';
                carry = 1;
            }
            else{
                carry = 0;
                tmp.s[i] = k + '0';
            }
        }
        return tmp;
    }

    friend CHugeInt operator+ (const int& a, const CHugeInt& b) {
        CHugeInt tmp(a);
        return tmp + b;
    }

    CHugeInt operator+ (const int& a) {
        CHugeInt tmp(a);
        return *this + tmp;
    }

    CHugeInt& operator+= (int a) {
        *this = *this + a;
        return *this;
    }

    CHugeInt operator++ () {    //前置++
        *this = *this + 1;
        return *this;
    }

    CHugeInt operator++(int) {  //后置++
        CHugeInt tmp(*this);    //后置++比前置++，时间慢的原因就是会有一次局部对象的生成   
        *this = *this + 1;
        return tmp;
    }

    friend ostream& operator<< (ostream& out, const CHugeInt& ch) {
        int len = strlen(ch.s);
        for(int i = len - 1; i >= 0; i--) {
            out << ch.s[i];
        }
        return out;
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}