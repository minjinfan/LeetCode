#include<iostream>
#include<vector>
#include<list>
// #include"leetCode/test.hpp"
#include "leetCode/function.h"
using namespace std;

int main(int argc, char** argv)
{
    Solution sl;

    // MyLinkedList myList;
    // myList.GenerateList(6);
    // cout << "old LinkList: " << endl;
    // myList.ShowListNode();

    // cout << endl << "run Code: " << endl;
    // Solution sl;
    // LinkNode *tmp = myList._dummyHead.next;

    // // LinkNode *qs203 = sl.removeElement(tmp, 4);
    // // LinkNode *qs19 = sl.removeNthFromEnd(tmp, 2);
    // // ShowLinkList(qs19);

    // vector<int> vecA = {1,3,5,7,9,11,13,15};

    // int fibNum = sl.fib(10);
    // cout << fibNum << endl;

    // int climbStairs = sl.climbStairs(9);
    // cout << "climbStairs:    " << climbStairs << endl;
    // cout << endl << "End of program" << endl;

    // vector<int> vec = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // int res = sl.minCostClimbingStairs(vec);
    // cout << res << endl;
    
    vector<int> vec = {2, 1, 1, 2};
    int res = sl.rob(vec);
    cout << res << endl;

    return 0;
}