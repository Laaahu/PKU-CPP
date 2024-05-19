/*
017:二维数组类
总时间限制: 1000ms 内存限制: 65536kB
描述
写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

输入
无
输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
样例输入
None
样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
private:
    int **p;
    int r, c;
public:
    Array2() {}
    Array2(int row, int col) {
        r = row, c = col;
        p = new int*[row];
        for (int i = 0; i < row; i++) {
            p[i] = new int[col];
        }
    }

    ~Array2() {
        if (p) {
            delete []p;
        }
    }

    int* operator[](int i) {
        return p[i];
        //重载的是 a[][]的第一个[] ，因为返回的是p[x],则第二个[]相当于取p[x]的第y个
    }

    int & operator()(int i, int j) {
        return p[i][j];
    }

    Array2(const Array2 &a) {   // 未用到
        if (p) delete []p;
        r = a.r;
        c = a.c;
        p = new int*[r];
        for (int i = 0; i < r; i++) {
            p[i] = new int[c];
        }
        memcpy(p, a.p, sizeof(int) * r * c);
    }

    Array2 & operator=(const Array2 &a) {
        if (p) delete []p;
        r = a.r;
        c = a.c;
        p = new int*[r];
        for (int i = 0; i < r; i++) {
            p[i] = new int[c];
        }
        memcpy(p, a.p, sizeof(int) * r * c);
        return *this;
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;        //需要重载[]访问
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";      //需要重载()实现数组访问
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;        //需要重载=实现深拷贝
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}