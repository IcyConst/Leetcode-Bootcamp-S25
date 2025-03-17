#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//234. Palindrome Linked List.
//First find the last half of the string(Using another point which jump 2 nodes at once).
//Then reverse the last half of the string, and compare the nodes one by one.


class Solution {
    public:
        ListNode* reverse(ListNode* head){
            ListNode* prev = nullptr;
            ListNode* cur = head;
            while(cur != nullptr){
                ListNode* next = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = next;
            }
            return prev;
        }
    
        bool isPalindrome(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* rev = reverse(slow);
            while (rev != nullptr) {
                if (head->val != rev->val) {
                    return false;
                }
                head = head->next;
                rev = rev->next;
            }
            return true;
        }
    };