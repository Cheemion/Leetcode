#include<iostream>
#include<list>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};
using std::list;
class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类  / 10;
            cur = cur % 1}0;
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        list<ListNode*> l1;
        while(head1 != nullptr) {
           l1.push_front(head1); 
           head1=head1->next;
        }
        list<ListNode*> l2;
        while(head2 != nullptr) {
           l2.push_front(head2); 
           head2 = head2->next;
        }
        int carry = 0;
        int cur = 0;
        ListNode* root = nullptr;
        while(!l1.empty() && !l2.empty()) {
            int val1 = l1.empty() ? 0 : l1.front()->val;
            int val2 = l2.empty() ? 0 : l2.front()->val;
            cur = val1 + val2 + carry;
            if(!l1.empty())
                l1.pop_front();
            if(!l2.empty())
                l2.pop_front();
            carry = cur / 10;
            cur = cur % 10; 
            if(root == nullptr) {
                root = new ListNode(cur);
            } else {
                ListNode* temp = new ListNode(cur);
                temp->next = root;
                root = temp;
            }
        }
        return root;
    }
};
int main(){
    return 1;
}