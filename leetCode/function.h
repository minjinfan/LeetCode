#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<iostream>
#include <string.h>
#include <vector>

#include "Common.hpp"
using namespace std;

class Solution
{
public:
    Solution(){}
    ~Solution(){}

    // question 203  给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
    LinkNode* removeElement(LinkNode* head, int val);

    // question 19 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点
    LinkNode* removeNthFromEnd(LinkNode* head, int n);

    // face02.07 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
    LinkNode *getIntersectionNode(LinkNode *headA, LinkNode *headB);

};

#endif