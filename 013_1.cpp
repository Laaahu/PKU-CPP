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
#include <cstring>
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

const hero_type_t army_make_hero_list[ARMY_TYPE_MAX_NUM][HERO_TYPE_MAX_NUM] = {
    {ICEMAN, LION, WOLF, NINJA, DRAGON},
    {LION, DRAGON, NINJA, ICEMAN, WOLF},
};

const string hero_str[HERO_TYPE_MAX_NUM] = {
    "dragon",
    "ninja",
    "iceman",
    "lion",
    "wolf"
};

const string army_str[ARMY_TYPE_MAX_NUM] = {
    "red",
    "blue"
};

int hero_health[HERO_TYPE_MAX_NUM];
int g_army_health_total[ARMY_TYPE_MAX_NUM];
int total;
int T;
int t;

typedef class hero_ {
private:
    int health;
    string name;
    int num;
    hero_type_t type;
public:
    hero_();
    hero_(int h, string n, hero_type_t t);
    void set_health(int h);
    int get_health();
    void set_num(int n);
    void num_inc();
    void num_dec();
    int get_num();
    string get_name();
} hero_t;

hero_t::hero_(int h, string n, hero_type_t t) {
    health = h;
    name = n;
    type = t;
    num = 0;
}

void hero_t::set_health(int h) {
    health = h;
}

int hero_t::get_health() {
    return health;
}

void hero_t::set_num(int n) {
    num = n;
}

void hero_t::num_inc() {
    num++;
}

void hero_t::num_dec() {
    num--;
}

int hero_t::get_num() {
    return num;
}
string hero_t::get_name() {
    return name;
}

typedef class army_ {
private:
    string name;
    int total_health;
    hero_t *hero[HERO_TYPE_MAX_NUM];
    bool make_finish;
    int make_hero_index;
    hero_type_t make_hero_list[HERO_TYPE_MAX_NUM];
    army_type_t type;
public:
    army_();
    army_(const string n, int th, army_type_t at);
    ~army_();
    bool make_hero_is_finish();
    string get_name();
    int get_health();
    bool make_hero();
    void print_make_hero_success_msg(hero_type_t hero);
    void print_make_hero_finish_msg();
}army_t;

army_t::army_(const string n, int th, army_type_t at) {
    name = n;
    total_health = th;
    make_finish = false;
    make_hero_index = 0;
    type = at;

    for (int i = 0; i < HERO_TYPE_MAX_NUM; i++) {
        hero[i] = new hero_t(hero_health[i], hero_str[i], hero_type_t(i));
        make_hero_list[i] = army_make_hero_list[type][i];
    }
}
army_t::~army_() {
    for (int i = 0; i < HERO_TYPE_MAX_NUM; i++) {
        delete hero[i];
    }
}

bool army_t::make_hero_is_finish() {
    return make_finish;
}

string army_t::get_name() {
    return name;
}

int army_t::get_health() {
    return total_health;
}

bool army_t::make_hero() {
    int i = make_hero_index;
    int cnt = 0;

    while (cnt < HERO_TYPE_MAX_NUM) {
        if (hero[make_hero_list[i]]->get_health() <= total_health) {
            hero[make_hero_list[i]]->num_inc();
            print_make_hero_success_msg(hero_type_t(make_hero_list[i]));
            total_health -= hero[make_hero_list[i]]->get_health();
            make_hero_index = (i + 1) % HERO_TYPE_MAX_NUM;
            return true;
        }
        
        i = (i + 1) % HERO_TYPE_MAX_NUM;
        cnt++;
    }

    print_make_hero_finish_msg();
    this->make_finish = true;
    return false;
}

void army_t::print_make_hero_success_msg(hero_type_t ht) {
    cout << setw(3) << setfill('0') << t << " ";
    cout << get_name() << " " << hero_str[ht] << " " << t + 1 << " born with strength ";
    cout << hero_health[ht] << "," << hero[ht]->get_num() << " " << hero_str[ht] << " in ";
    cout << get_name() << " headquarter" << endl;
}

void army_t::print_make_hero_finish_msg() {
    cout << setw(3) << setfill('0') << t << " " << get_name() << " ";
    cout << "headquarter stops making warriors" << endl;
}

typedef class game_ {
private:
    army_t *army[ARMY_TYPE_MAX_NUM];    
public:
    game_();
    ~game_();
    void begin();
    bool all_army_make_hero_is_finish();
}game_t;

game_t::game_() {
    for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
        army[i] = new army_(army_str[i], total, army_type_t(i));
    }
}

game_t::~game_() {
    for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
        delete army[i];
    }
}

void game_t::begin() {
    for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
        if (army[i]->make_hero_is_finish()) continue;
        army[i]->make_hero();
    }
}

bool game_t::all_army_make_hero_is_finish() {
    for (int i = 0; i < ARMY_TYPE_MAX_NUM; i++) {
        if (!army[i]->make_hero_is_finish()) {
            return false;
        }
    }

    return true;
}

int main() {
    int case_cnt = 1;
    cin >> T;

    while (T--) {
        t = 0;
        cin >> total;

        for (int i = 0; i < HERO_TYPE_MAX_NUM; i++) {
            cin >> hero_health[i];
        }

        cout << "Case:" << case_cnt << endl;
        game_t *game = new game_t();
        while (1) {
            game->begin();
            if (game->all_army_make_hero_is_finish()) {
                delete game;
                break;
            }
            t++;
        }

        case_cnt++;
    }
}
