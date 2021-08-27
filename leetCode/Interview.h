#ifndef INTERVIEW_H_
#define INTERVIEW_H_

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>

// #include "Common.hpp"
using namespace std;

class Interview
{
public:
    Interview() {}
    ~Interview() {}


    /****************************************    输入训练    ****************************************/

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
    */
    int input7();


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
};


#endif  // INTERVIEW_H_