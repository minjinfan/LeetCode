#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<iostream>
#include <string.h>
#include <vector>
#include <map>
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
    
    // 509. 斐波那契数    通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和
    int fib(int N);

    // 70. 爬楼梯    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢 
    int climbStairs(int n);

    // 746. 使用最小花费爬楼梯    数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
    int minCostClimbingStairs(vector<int>& cost);

    // 198. 打家劫舍    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
    int rob(vector<int>& nums);
    // 213. 打家劫舍 II   你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 
    int rob2(vector<int>& nums);
    // 740. 删除并获得点数    给你一个整数数组 nums ，你可以对它进行一些操作。每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
    int deleteAndEarn(vector<int>& nums);

    double GaussIntegral_1D();
    void TransformIntegraInterval();
};

#endif