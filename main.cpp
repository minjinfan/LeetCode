#include<iostream>
// #include"leetCode/test.hpp"
#include "leetCode/function.h"
using namespace std;

int main(int argc, char* argv)
{
    MyLinkedList myList;
    myList.GenerateList(6);
    cout << "old LinkList: " << endl;
    myList.ShowListNode();

    cout << endl << "run Code: " << endl;
    Solution sl;
    LinkNode *tmp = myList._dummyHead.next;
    // LinkNode *qs203 = sl.removeElement(tmp, 4);
    LinkNode *qs19 = sl.removeNthFromEnd(tmp, 2);
    ShowLinkList(qs19);

  
    return 0;
}