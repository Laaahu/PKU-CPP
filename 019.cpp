/*
019:全面的MyString
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果

输入
无
输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
样例输入
无
样例输出
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
*/

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
private:
    char *p;
    int len;
public:
    MyString() {
        p = NULL;
        len = 0;
    }

    MyString(char *c) {
        int n = strlen(c);
        p = new char[n + 1];
        strcpy(p, c);
        len = n;
    }

    // MyString(const MyString &ms) {
    //     if (p) delete []p;
    //     p = new char[strlen(ms.p) + 1];
    //     strcat(p, ms.p);
    //     len = strlen(ms.p);
    // }

    friend ostream& operator<<(ostream &os, MyString &ms) {
        if (ms.p == NULL) {
            os << "";
        } else {
            os << ms.p;
        }
        return os;
    }

    MyString operator+ (const MyString &a) {
        MyString ms;
        ms.p = new char[len + strlen(a.p) + 1];
        strcat(ms.p, p);
        strcat(ms.p + len, a.p);
        return ms;
    }

    char& operator[](int i) {
        return p[i];
    }

    MyString& operator+= (const char *s) {
        char *tmp;
        if (p) {
            tmp = new char[len + 1];
            strcat(tmp, p);
            delete []p;
        }

        p = new char[len + strlen(s) + 1];
        strcat(p, tmp);
        strcat(p, s);
        len = len + strlen(s);
        delete []tmp;
        return *this;
    }

    friend MyString operator+ (const char *s, const MyString &ms) {
        MyString mys;
        mys.p = new char[strlen(s) + ms.len + 1];
        strcat(mys.p, s);
        strcat(mys.p + strlen(s), ms.p);
        mys.len = strlen(s) + ms.len;
        return mys;       
    }

    bool operator<(const MyString &ms) {
        return strcmp(p, ms.p) == -1;
    }

    bool operator==(const MyString &ms) {
        return strcmp(p, ms.p) == 0;
    }

    bool operator>(const MyString &ms) {
        return strcmp(p, ms.p) == 1;
    }

    char* operator()(int i, int length){
        char *cp = new char[length + 1];
        int x;
        for (x = 0; x < length; x++, i++) {
            cp[x] = p[i];
        }

        cp[x] = 0;
        return cp;
    }
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}