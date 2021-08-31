#ifndef INTERVIEW_H_
#define INTERVIEW_H_

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>
#include <utility>

// #include "Common.hpp"
using namespace std;

struct monster;
class Interview
{
public:
    Interview() {}
    ~Interview() {}


    /****************************************    输入训练    ****************************************/
    // https://ac.nowcoder.com/acm/contest/5657#question

    /*
        输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
        接下来t行, 每行一组数据。
        每行的第一个整数为整数的个数n(1 <= n <= 100)。
        接下来n个正整数, 即需要求和的每个正整数。
    */
    int input5();

    /*
        输入数据有多组, 每行表示一组输入数据。
        每行的第一个整数为整数的个数n(1 <= n <= 100)。
        接下来n个正整数, 即需要求和的每个正整数。
    */
    int input6();

    /*
        输入数据有多组, 每行表示一组输入数据。
        每行不定有n个整数，空格隔开。(1 <= n <= 100)。
        对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
    */
    int input7();

    /*
        多个测试用例，每个测试用例一行。
        每行通过,隔开，有n个字符，n＜100
    */
    int input10();


    // 字符串长度计算和截取 
    char StringLengthCalculationAndInterception(string str);
    vector<string> split(const string& str,const string& delim); 


    /*  买票问题
        现在有n个人排队买票，已知是早上8点开始卖票，这n个人买票有两种方式：
        第一种是每一个人都可以单独去买自己的票，第 i 个人花费 a[i] 秒。
        第二种是每一个人都可以选择和自己后面的人一起买票，第 i 个人和第 i+1 个人一共花费 b[i] 秒。
        最后一个人只能和前面的人一起买票或单独买票。
        由于卖票的地方想早些关门，所以他想知道他最早几点可以关门，请输出一个时间格式形如：08:00:40 am/pm
        时间的数字要保持 2 位，若是上午结束，是 am ，下午结束是 pm
    */
   int BuyTicket();


    // 16进制转10进制
    void transfrom(char &c, int i, long long int &res);
    void BaseConversion_HtoD();

    // 回合制打怪兽
    int FightMonsters();
    bool defende(int &mainA, int &mainB, int &mainC, monster &m, int &add);
    bool Track(int &mainA, int &mainB, int &mainC, monster &m);


    // 厨师煮饭
    int ChefCooking();


    /****************************************    DP  网格   迷宫   ****************************************/

    /*
        给你一个 m * n 的网格，其中每个单元格不是 0（空）就是 1（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。
        如果您 最多 可以消除 k 个障碍物，请找出从左上角 (0, 0) 到右下角 (m-1, n-1) 的最短路径，并返回通过该路径所需的步数。如果找不到这样的路径，则返回 -1。
    */
   // 1293. 网格中的最短路径   最多可以消除 k 个障碍物
    int shortestPath(vector<vector<int>>& grid, int k);


    /*
        在一个 106 x 106 的网格中，每个网格上方格的坐标为 (x, y) 。
        现在从源方格 source = [sx, sy] 开始出发，意图赶往目标方格 target = [tx, ty] 。数组 blocked 是封锁的方格列表，其中每个 blocked[i] = [xi, yi] 表示坐标为 (xi, yi) 的方格是禁止通行的。
        每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 不 在给出的封锁列表 blocked 上。同时，不允许走出网格。
        只有在可以通过一系列的移动从源方格 source 到达目标方格 target 时才返回 true。否则，返回 false
    */
    // 1036. 逃离大迷宫  有障碍
    bool EscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);


    // 数独
    bool Sudoku_check(vector<vector<int>> &vec, int x, int y, int val);
    bool Sudoku_DFS(vector<vector<int>>  &vec, int n);
    void Sudoku();
};







struct monster
{
    int A;
    int B;
    int C;
    monster(){}
    monster(int a, int b, int c) : A(a), B(b), C(c) {}
};

static bool monster_cmp(monster a, monster b){
    return a.C < b.C;
};

static int Sudoku_a[9][9] ={
  {7,2,6,9,0,4,0,5,1},
  {0,8,0,6,0,7,4,3,2},
  {3,4,1,0,8,5,0,0,9},
  {0,5,2,4,6,8,0,0,7},
  {0,3,7,0,0,0,6,8,0},
  {0,9,0,0,0,3,0,1,0},
  {0,0,0,0,0,0,0,0,0},
  {9,0,0,0,2,1,5,0,0},
  {8,0,0,3,0,0,0,0,0}
};


#endif  // INTERVIEW_H_