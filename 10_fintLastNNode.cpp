#include<iostream>
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        for(int i = 0; i < n - 1; i++) {
            tail = tail->next;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(tail->next != nullptr) {
            tail = tail->next;
            pre = cur;
            cur = cur->next;
        }
        if(pre != nullptr) {
            pre->next = cur->next;
        } else {
            head = head->next;
        }
        return head;
        // write code here
    }
};

int main() {

    return 0;
}