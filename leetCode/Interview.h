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
// #include <Common.hpp>


// #include "Common.hpp"
using namespace std;

struct coor{
    int x;
    int y;
    coor(){}
    coor(int x_, int y_) : x(x_), y(y_) {} 

    bool operator==(const coor &s) const
    {
        return (s.x == x) && (s.y == y);
    }

};

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

    
    /*
     有一个数组a[N]顺序存放0~N-1，要求  每隔两个数  删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
     以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
    */
    // 删数  
    int DeleteNum();


    // 扑克牌游戏
    int PokerGame();

    /*
        1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
        2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
        3.输入的文件可能带路径，记录文件名称不能带路径
    */
    // 简单错误记录
    int Errorlog();


    /*
        Catcher是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，ABA，A，123321，
        但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。
        因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，
        他只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？
    */
    // 密码截取
    int PasswordInterception();


    // 剑指 Offer 47. 礼物的最大价值
    int maxValue(vector<vector<int>>& grid);


    // 二分法 山脉数组中查找目标值
    // int findInMountainArray(int target, MountainArray &mountainArr)


    /*
            给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
        在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执
        行不同的任务，或者在待命状态。
            你需要计算完成所有任务所需要的 最短时间
    */
    // 621. 任务调度器
    int leastInterval(vector<char>& tasks, int n);



    //  和为S的连续正数序列
    vector<vector<int> > FindContinuousSequence(int sum) ;


    // NC55 最长公共前缀
    string longestCommonPrefix(vector<string>& strs);


    // 字符串加密
    int StringEncryption();


    /*
        某比赛已经进入了淘汰赛阶段,已知共有n名选手参与了此阶段比赛，他们的得分分别是a_1,a_2….a_n,小美作为比赛的裁判希望设定一个分数线m，使得所有分数大于m的选手晋级，其他人淘汰。
        但是为了保护粉丝脆弱的心脏，小美希望晋级和淘汰的人数均在[x,y]之间。
        显然这个m有可能是不存在的，也有可能存在多个m，如果不存在，请你输出-1，如果存在多个，请你输出符合条件的最低的分数线。
    */
   // 比赛选分数
   int MT1();



   /*\
    为了不断优化推荐效果，今日头条每天要存储和处理海量数据。假设有这样一种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，
    每个用户都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户）中，有多少用户对这类文章喜好值为k。因为一些特殊的原因，
    不会出现一个查询的用户区间完全覆盖另一个查询的用户区间(不存在L1<=L2<=R2<=R1)。
   */
  // 用户喜好
    int ZJ_userhobby();



    /*
        给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
    */
    int subarraySum(vector<int>& nums, int k);


    // 974. 和可被 K 整除的子数组
    int subarraysDivByK(vector<int>& nums, int k) ;


    /*
        862. 和至少为 K 的最短子数组
    */
   int shortestSubarray(vector<int>& A, int K);







    /****************************************    DP  网格   迷宫   ****************************************/

    int next[4][2] = {{1,0}, {-1,0}, {0,1}, {0, -1}};
    int next2[2][2] = {{1,0},  {0,1}};


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
    // 1036. 能否逃离大迷宫  有障碍
    bool EscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);



    // 从起点出发达到终点的路线个数
    void NumberEscapePossible();
    void NumberEscapePossible_DFS(vector<vector<bool>> &visited, coor &start);
    coor EscapePossible_start ;
    coor EscapePossible_end ;
    int  NumEP = 0;   int EscapePossible_R;    int EscapePossible_C;
    vector<vector<bool>> blocked;
    vector<vector<pair<int, int>>> pathEP;    // 路径



    // 数独
    void Sudoku();
    bool Sudoku_check(vector<vector<int>> &vec, int x, int y, int val);
    bool Sudoku_DFS(vector<vector<int>>  &vec, int n);
    


    // 200. 岛屿数量
    int numIslands();
    void numIslands_DFS(vector<vector<string>>& grid, int x, int y);


    /*
        用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
        如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子
    */
    // 矩阵中的路径
    bool hasPath(vector<vector<char> >& matrix, string word); 
    bool hasPath_dfs(vector<vector<char>> &matrix, int x, int y, int idx, vector<vector<bool>> &visited);
    string hasPath_target;


    /*
        我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，从同一个方向看总共有多少种不同的方法
    */
    // JZ10 矩形覆盖
    int rectCover(int number) ;



    /*
        机器人在编号为0的建筑处。每一步，它跳到下一个（右边）建筑。假设机器人在第k个建筑，且它现在的能量值是E, 下一步它将跳到第个k+1建筑。
        它将会得到或者失去正比于与H(k+1)与E之差的能量。如果 H(k+1) > E 那么机器人就失去 H(k+1) - E 的能量值，否则它将得到 E - H(k+1) 的能量值。
        游戏目标是到达第个N建筑，在这个过程中，能量值不能为负数个单位。现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏
    */
    // 初始能量或者血量问题
    int InitialEnergy();


    /*
        有1分，2分，5分，10分四种硬币，每种硬币数量无限，给定n分钱(n <= 100000)，有多少中组合可以组成n分钱？
    */
    // 硬币划分
    int CoinDivision();


    // 路由器传包、  贼偷窃 问题
    int HJRout();
    int HJRout2();  // 首尾相连



    // 最长回文子串
    string longestPalindrome(string s);


    // //  23. 合并K个升序链表     见 function.h
    // ListNode* mergeKLists(vector<ListNode*>& lists);
    // ListNode* mergeTwoList(ListNode* a, ListNode* b);


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

static vector<vector<int>> Possible_a ={
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,1,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0}

    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

// static vector<vector<int>> Possible_a = {
//   {0,1,0,},
//   {0,1,0,},
//   {0,0,0,}
// };

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

static vector<vector<string>> numIslands_a ={
  {"1","1","0","0","0"},
  {"1","1","0","0","0"},
  {"0","0","1","0","0"},
  {"0","0","0","1","1"}
};

#endif  // INTERVIEW_H_