#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef double real;
typedef std::vector<double> vec3;
typedef std::vector<double> vec2;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList
{
public:
    int _size = 0;
    ListNode _dummyHead; 
    MyLinkedList(){
        int _size = 0;
        _dummyHead = ListNode();
    }
    ~MyLinkedList(){
        ListNode *cur = &_dummyHead;
        while(cur->next != nullptr){
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        // delete cur;

    }

    void addAtHead(int val) {
        ListNode *newHead = new ListNode(val);
        ListNode *cur = &_dummyHead;
        newHead->next = cur->next;
        cur->next = newHead;
        _size++;
    }

    void addAtTail(int &val){
        ListNode *newNode = new ListNode(val);
        ListNode *cur = &_dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        ++_size;
    }

    void GenerateList(int n)
    {
        for(int i = n; i > 0; i--){
            addAtHead(i);
        }
    }

    void ShowListNode()
    {
        ListNode *cur = &_dummyHead;
        while(cur->next != nullptr){
            cout << cur->next->val << "\t";
            cur = cur->next;
        }
        // delete cur;
    }
};


inline void ShowLinkList(ListNode *List)
{
    ListNode dummyHead;
    dummyHead.next = List;
    ListNode *cur = &dummyHead;
    while(cur->next != nullptr){
        cout << cur->next->val << "\t";
        cur = cur->next;
    }
}

// Y = a * x + b
inline void faxpBy(vector<double> &Y, real& a, vector<double> &X, vector<double> &B)
{
	for(int i = 0; i < 3; ++i){
		Y[i] = a * X[i] + B[i];
	}
}


inline vec3 SubEq(const vec3 &X, const vec3 &Y)
{
	vec3 res(3,0);
	for(int i = 0; i < 3; ++i){
		res[i] = X[i] - Y[i];
	}
	return res;
}

inline double norm(const vec3 &X)
{
    return sqrt(pow(X[0],2) + pow(X[1],2) + pow(X[2],2));
}

inline void showVec(vector<int> vec)
{
    for(auto i : vec){
        cout << i << "  ";
    }
    cout << endl;
}