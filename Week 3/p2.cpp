#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//143. Reorder List
//Each time, link the current node with the last node of the list(use another pointer to find that).
//Then link the last node to the next node of the current node.
//Repeat the process until the last node is the same as the next node.(The list has ended.)

class Solution {
    public:
        void reorderList(ListNode* head) {
            while(head->next != nullptr){
                ListNode* cur = head;
                ListNode* nextpos = cur->next;
                ListNode* prev = nullptr;
                while(cur->next != nullptr) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = nullptr;
                head->next = cur;
                if(cur != nextpos) cur->next = nextpos;
                head = nextpos;
            }
        }
    };