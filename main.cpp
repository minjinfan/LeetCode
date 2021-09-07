#include<iostream>
#include<vector>
#include<list>
#include <string>
#include "leetCode/function.h"
#include "leetCode/Interview.h"
#include "leetCode/DP.h"

using namespace std;

vector<int> fun(vector<int> pre, int forward, int cache)
{
    int sent1 = min(forward, pre[0]);

    int redis = pre[0] > forward ? pre[0] - forward : 0;
    redis = min(redis, cache);

    int sent2 = min(pre[1] + redis, forward);

    return {sent1, sent2};
}

struct tmp1{  // 重写仿函数
    bool operator() (int a, int b){
        return a < b;  // 大顶堆  大的在前面
        // return a < b;  //小顶堆  小的在前面
    }
};
struct tmp2{  // 重载运算符
    int x;
    tmp2(int a) { x = a; }

    bool operator <(const tmp2& a) const
    {
        return x < a.x;    // 大顶堆
    }
};

int main(int argc, char** argv)
{
    
    // 输入  scanf   与   getline
    /* scanf
    int a, b;

    scanf("%d %d", &a, &b);             // 1 2  --> a=1  b=2
    cout << a << "  " << b << endl;

    scanf("%d,%d", &a, &b);             // 1,2  --> a=1  b=2
    cout << a << "  " << b << endl;

    scanf("%4d%4d", &a, &b);            // 12345678  -->  a=1234   b=5678
    cout << a << "  " << b << endl;

    const char Teststr[] ="7,8";  // 必须是 const char []      --> a = 7  b= 8
    string str1;
    sscanf(Teststr, "%d,%d", &a, &b);
    cout << a << "  " << b << endl;
    */

   /*  getline
    // 键盘输入    1,2 3,4 5,6 7,8
    string s;
    while(getline(cin, s)){ 
        stringstream ss(s);
        vector<string> vec;
        while(getline(ss, s, ',')){
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size() - 1; ++i){
            cout << vec[i] << ",";
        }
        cout << vec[vec.size() - 1] << endl;;
    }
    */

   /* 优先队列 用法
        // priority_queue<int, vector<int>, tmp1> Q;
        priority_queue<tmp2> Q;

        for(int i = 0; i < vec.size(); ++i){
            Q.push(vec[i]);
        }
        while(!Q.empty()){
            // cout << Q.top() << " ";
            cout << Q.top().x << " ";
            Q.pop();
        }
   */

    vector<int> vec = {3,1,5,4,7,9,3,8,2,6};
    Interview itview;
    Solution sl;
//    sl.quickSort(vec);
//    showVec(vec);

    // priority_queue<int, vector<int>, tmp1> Q;
    priority_queue<tmp2> Q;

    for(int i = 0; i < vec.size(); ++i){
        Q.push(vec[i]);
    }
    while(!Q.empty()){
        // cout << Q.top() << " ";
        cout << Q.top().x << " ";
        Q.pop();
    }


    cout << endl;
    return 0;

}