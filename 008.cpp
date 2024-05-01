/*
008:超简单的复数类

描述
下面程序的输出是：

3+4i
5+6i

请补足Complex类的成员函数。不能加成员变量。
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }

// 在此处补充你的代码
    Complex& operator= (const string s) {
        r = s[0] - '0';
        i = s[2] - '0';
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();  //等价于a.operator=("3+4i")
    a = "5+6i"; a.Print();  //等价与a.operator=("5+6i")
    return 0;
}