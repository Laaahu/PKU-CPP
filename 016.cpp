/*
016:惊呆！Point竟然能这样输入输出
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空

输入
多组数据，每组两个整数
输出
对每组数据，输出一行，就是输入的两个整数
样例输入
2 3
4 5
样例输出
2,3
4,5
*/

#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
// 在此处补充你的代码
    friend istream & operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream & operator<<(ostream &os, Point &p) {
        os << p.x << "," << p.y;
        return os;
    }  
}; 
int main() 
{ 
 	Point p;
 	while(cin >> p) {
 		cout << p << endl;
	 }
	return 0;
}