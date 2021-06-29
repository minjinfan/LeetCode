#include"function.h"

LinkNode* Solution::removeElement(LinkNode* head, int val)
{
      LinkNode *dummyNode = new LinkNode();
        dummyNode->next = head;
        LinkNode *cur = dummyNode;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                LinkNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete  tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;

        return head;
}

LinkNode* Solution::removeNthFromEnd(LinkNode* head, int n)
{
     LinkNode* dummyHead = new LinkNode(-1);
    // ListNode dummyHead;
    dummyHead->next = head;
    LinkNode* fast = dummyHead;
    LinkNode* slow = dummyHead;
    while(n-- > 0 && fast->next != nullptr){
        fast = fast->next;
    }

    fast = fast->next;
    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummyHead->next;
}

LinkNode* Solution::getIntersectionNode(LinkNode *headA, LinkNode *headB)
{
    LinkNode* A = headA;
    LinkNode* B = headB;
    int lenA = 0, lenB = 0;
    while(A != nullptr){
        lenA++;
        A = A->next;
    }
    while(B != nullptr){
        lenB++;
        B = B->next;
    }
    A = headA;
    B = headB;
    if(lenB > lenA){
        swap(A, B);
        swap(lenA, lenB);
    }
    int delta = lenA - lenB;
    while(delta--){
        A = A->next;
    }
    while(A != nullptr){
        if(A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}

LinkNode *Solution::detectCycle(LinkNode *head)
{
     LinkNode* fast = head;
        LinkNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                LinkNode* node1 = fast;
                LinkNode* node2 = head;
                while(node1 != node2){
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node2;
            }
        }
        return NULL;
}