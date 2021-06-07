#include<iostream>
// #include"leetCode/test.hpp"
#include "leetCode/function.h"
using namespace std;

int main(int argc, char* argv)
{
    MyLinkedList myList;
    myList.GenerateList(6);
    myList.ShowListNode();

    Solution sl;
    LinkNode *tmp = myList._dummyHead.next;
    LinkNode *qs203 = sl.removeElement(tmp, 4);
    ShowLinkList(qs203);

  
    return 0;
}