#include <iostream>
#include <vector>

using namespace std;
typedef double real;
typedef std::vector<double> vec3;
typedef std::vector<double> vec2;
struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode() : val(0), next(nullptr) {}
    LinkNode(int x) : val(x), next(nullptr) {}
    LinkNode(int x, LinkNode *next) : val(x), next(next) {}
};

class MyLinkedList
{
public:
    int _size = 0;
    LinkNode _dummyHead; 
    MyLinkedList(){
        int _size = 0;
        _dummyHead = LinkNode();
    }
    ~MyLinkedList(){
        LinkNode *cur = &_dummyHead;
        while(cur->next != nullptr){
            LinkNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        // delete cur;

    }

    void addAtHead(int val) {
        LinkNode *newHead = new LinkNode(val);
        LinkNode *cur = &_dummyHead;
        newHead->next = cur->next;
        cur->next = newHead;
        _size++;
    }

    void addAtTail(int &val){
        LinkNode *newNode = new LinkNode(val);
        LinkNode *cur = &_dummyHead;
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
        LinkNode *cur = &_dummyHead;
        while(cur->next != nullptr){
            cout << cur->next->val << "\t";
            cur = cur->next;
        }
        // delete cur;
    }
};


inline void ShowLinkList(LinkNode *List)
{
    LinkNode dummyHead;
    dummyHead.next = List;
    LinkNode *cur = &dummyHead;
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