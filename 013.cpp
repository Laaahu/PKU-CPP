/*
013:魔兽世界之一：备战
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/

#include <iostream>
#include <iomanip>

using namespace std;

#define HERO_NAME_MAX_LENGTH 10
#define ARMY_NAME_MAX_LENGTH 10

typedef enum hero_type_ {
    DRAGON,
    NINJA,
    ICEMAN,
    LION,
    WOLF,
    HERO_TYPE_MAX_NUM
} hero_type_t;

typedef enum army_type_ {
    RED,
    BULE,
    ARMY_TYPE_MAX_NUM
}army_type_t;

const int army_make_hero_list[ARMY_TYPE_MAX_NUM][HERO_TYPE_MAX_NUM] = {
    {ICEMAN, LION, WOLF, NINJA, DRAGON},
    {LION, DRAGON, NINJA, ICEMAN, WOLF},
};

const char hero_str[HERO_TYPE_MAX_NUM][HERO_NAME_MAX_LENGTH] = {
    "dragon",
    "ninja",
    "iceman",
    "lion",
    "wolf"
};

const char army_str[ARMY_TYPE_MAX_NUM][ARMY_NAME_MAX_LENGTH] = {
    "red",
    "blue"
};

int hero_health[HERO_TYPE_MAX_NUM];
int g_army_hero_num[ARMY_TYPE_MAX_NUM][HERO_TYPE_MAX_NUM] = {0};
bool army_make_hero_finish[ARMY_TYPE_MAX_NUM] = {false, false};
int g_army_make_hero_index[ARMY_TYPE_MAX_NUM] = {0, 0};
int g_army_health_total[ARMY_TYPE_MAX_NUM];
int total;
int T;
int t;

typedef class hero_ {
private:
    int health;
public:
    hero_(int h) {
        health = h;
    }
} hero_t;

bool all_army_make_hero_over_check() {
    for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
        if (!army_make_hero_finish[i]) {
            return false;
        }
    }

    return true;
}

void print_success_msg(army_type_t army, hero_type_t hero) {
    cout << setw(3) << setfill('0') << t << " ";
    cout << army_str[army] << " " << hero_str[hero] << " " << t + 1 << " born with strength ";
    cout << hero_health[hero] << "," << g_army_hero_num[army][hero] << " " << hero_str[hero] << " in ";
    cout << army_str[army] << " headquarter" << endl;
}

void print_finish_msg(army_type_t army) {
    cout << setw(3) << setfill('0') << t << " " << army_str[army] << " ";
    cout << "headquarter stops making warriors" << endl;
}

bool make_hero(army_type_t army) {
    int i = g_army_make_hero_index[army];
    int cnt = 0;

    while (cnt < HERO_TYPE_MAX_NUM) {
        if (hero_health[army_make_hero_list[army][i]] <= g_army_health_total[army]) {
            g_army_health_total[army] -= hero_health[army_make_hero_list[army][i]];
            g_army_hero_num[army][army_make_hero_list[army][i]]++;
            print_success_msg(army, hero_type_t(army_make_hero_list[army][i]));
            g_army_make_hero_index[army] = (i + 1) % HERO_TYPE_MAX_NUM;
            return true;
        }
        
        i = (i + 1) % HERO_TYPE_MAX_NUM;
        cnt++;
    }

    return false;
}

int main() {
    int case_cnt = 1;
    cin >> T;

    while (T--) {
        t = 0;
        cin >> total;
        for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
            g_army_health_total[i] = total;
            army_make_hero_finish[i] = false;
            g_army_make_hero_index[i] = 0;
            for (int j = 0; j < HERO_TYPE_MAX_NUM; j++) {
                g_army_hero_num[i][j] = 0;
            }
        }

        for (int i = 0; i < HERO_TYPE_MAX_NUM; i++) {
            cin >> hero_health[i];
        }

        cout << "Case:" << case_cnt << endl;
        while (1) {       
            for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
                if (army_make_hero_finish[i]) continue;

                if (!make_hero(army_type_t(i))) {
                    print_finish_msg(army_type_t(i));
                    army_make_hero_finish[i] = true;
                }
            }

            if (all_army_make_hero_over_check()) {
                break;
            }

            t++;
        }

        case_cnt++;
    }
}