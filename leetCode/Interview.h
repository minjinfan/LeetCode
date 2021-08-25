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

    // 字符串长度计算和截取 
    char StringLengthCalculationAndInterception(string str);
    vector<string> split(const string& str,const string& delim); 

};


#endif  // INTERVIEW_H_