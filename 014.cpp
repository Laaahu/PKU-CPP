/*
014:MyString
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
补足MyString类，使程序输出指定结果

输入
多组数据，每组一行，是两个不带空格的字符串
输出
对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次
样例输入
abc def
123 456
样例输出
abc,abc,abc
def,def,def
123,123,123
456,456,456
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
// 在此处补充你的代码
    MyString() {
        p = NULL;
    }

    MyString(const MyString &ms) {
        if (ms.p) {
            p = new char[strlen(ms.p) + 1];
            strcpy(p, ms.p);
            p[strlen(ms.p)] = '\0';
        } else {
            p = NULL;
        }
    }

    void Copy(char *c) {
        if (c) {
            p = new char[strlen(c) + 1];
            strcpy(p, c);
            p[strlen(c)] = '\0';
        } else {
            p = NULL;
        }
    }

    friend ostream & operator<<(ostream &os, const MyString &s) {
        os << s.p;
        return os;
    }

    MyString & operator=(const MyString &ms) {
        if (p) {
            delete []p;
        }

        if (ms.p) {
            p = new char[strlen(ms.p) + 1];
            strcpy(p, ms.p);
            p[strlen(ms.p)] = '\0'; 
        } else {
            p = NULL;
        }

        return *this;
    }
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;    //需要构造函数MyString(const char * s)、复制构造函数MyString(const MyString &ms)
		MyString s3(NULL);  //需要构造函数MyString()
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;    //需要构造函数MyString(const char * s)
		s3 = s2;    //需要重载=
		s1 = s3;    //需要重载=
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}