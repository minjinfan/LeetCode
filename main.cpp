#include<iostream>
#include<vector>
#include<list>
#include <string>
// #include"leetCode/test.hpp"
#include "leetCode/function.h"
#include "leetCode/Interview.h"

using namespace std;

int main(int argc, char** argv)
{
    Solution sl;
    
    Interview itview;


    string ss = "aaa<2>bbbbb</>abcd";
    char c = itview.StringLengthCalculationAndInterception(ss);
    

    return 0;
}