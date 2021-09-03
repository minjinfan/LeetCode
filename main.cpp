#include<iostream>
#include<vector>
#include<list>
#include <string>
#include "leetCode/function.h"
#include "leetCode/Interview.h"

using namespace std;

vector<int> fun(vector<int> pre, int forward, int cache)
{
    int sent1 = min(forward, pre[0]);

    int redis = pre[0] > forward ? pre[0] - forward : 0;
    redis = min(redis, cache);

    int sent2 = min(pre[1] + redis, forward);

    return {sent1, sent2};
}

int main(int argc, char** argv)
{
   
    Interview itview;
    // itview.HJRout2();
    itview.StringEncryption();

    // cout << "Hello Word \n";
    return 0;
}
