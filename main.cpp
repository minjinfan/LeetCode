#include<iostream>
#include<vector>
#include<list>
// #include"leetCode/test.hpp"
#include "leetCode/function.h"
using namespace std;

int main(int argc, char* argv)
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

    int fibNum = sl.fib(10);
    cout << fibNum << endl;

    cout << "End of program" << endl;
    return 0;
}