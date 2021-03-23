#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* quick = head;
        while(1) {
            slow = slow->next;
            quick = quick->next;
            if(quick == nullptr) 
                return nullptr;
            quick = quick->next;
            if(quick == nullptr) 
                return nullptr;
            if(quick == slow)
                break;
        }
        while(head!=slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
int main() {
    return 1;
}