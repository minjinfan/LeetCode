#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>

#include "Common.hpp"
using namespace std;

class Solution
{
public:
    Solution(){}
    ~Solution(){}

    /****************************************    链表    ****************************************/

    // question 203  给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
    LinkNode* removeElement(LinkNode* head, int val);

    // question 19 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点
    LinkNode* removeNthFromEnd(LinkNode* head, int n);

    // face02.07 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
    LinkNode *getIntersectionNode(LinkNode *headA, LinkNode *headB);

    // question 142   给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中
    LinkNode *detectCycle(LinkNode *head);

    void Readfile();



    /****************************************    动态规划    ****************************************/
    
    //509. 斐波那契数    通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和
    int fib(int N);

};

#endif