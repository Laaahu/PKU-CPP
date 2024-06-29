/*
031:山寨版istream_iterator
描述
模仿C++标准模板库istream_iterator用法，实现CMyistream_iterator使得程序按要求输出

输入
第一行是整数t，表示有t组数据
每组数据一行，三个整数加两个字符串。字符串是不含空格的
输出
对每组数据，输出二行
在第一行输出第一个数
第二行原样输出输入的内容
样例输入
2
79 90 20 hello me
12 34 19 take up
样例输出
79
79 90 20 hello me
12
12 34 19 take up
*/

#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
// 在此处补充你的代码 
private:
    T key;
    istream &my_cin;
public:
    CMyistream_iterator(istream &is):my_cin(is) {
        my_cin>> key;
    }

    T operator *() {
        return key;
    }

    istream& operator++(int) {
        my_cin >> key;
        return my_cin;
    }
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //读入 n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //读入 n2
		 inputInt ++;
		 n3 = * inputInt; //读入 n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}