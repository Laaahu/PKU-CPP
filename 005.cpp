/*
005:编程填空：学生信息处理程序

描述
实现一个学生信息处理程序，计算一个学生的四年平均成绩。

要求实现一个代表学生的类，并且类中所有成员变量都是【私有的】。

补充下列程序中的 Student 类以实现上述功能。

输入
输入数据为一行，包括：
姓名,年龄,学号,第一学年平均成绩,第二学年平均成绩,第三学年平均成绩,第四学年平均成绩。
其中姓名为由字母和空格组成的字符串（输入保证姓名不超过20个字符，并且空格不会出现在字符串两端），年龄、学号和学年平均成绩均为非负整数。信息之间用逗号隔开。
输出
输出一行数据，包括：
姓名,年龄,学号,四年平均成绩。
信息之间用逗号隔开。

样例输入
Tom Hanks,18,7817,80,80,90,70
样例输出
Tom Hanks,18,7817,80
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
private:
    char name[25];
    unsigned int age;
    unsigned int no;
    unsigned int sorce[4];
    float arv;
public:
    Student() {}
    void input() {
        cin.getline(name, 20, ',');
        cin >> age;
        if (cin.get() == ',') {
            cin >> no;
        }

        for (int i = 0; i < 4; i++) {
            if (cin.get() == ',') {
                cin >> sorce[i];
            }
        }
    }

    void calculate() {
        arv = 0;
        for (int i = 0; i < 4; i++) {
            arv += sorce[i];
        }

        arv /= 4;
    }

    void output() {
        cout << name << "," << age << "," << no << "," << arv << endl;
    }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}