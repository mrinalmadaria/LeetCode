#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverse(ListNode * head){
        if(!head) return head;
        ListNode * prev = NULL;
        ListNode *curr = head;
        ListNode *nextnode = NULL;
        while(curr!=NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast !=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
            }
        ListNode *ReverseHead = reverse(slow);
        ListNode *temp1 = head;
        ListNode *temp2 = ReverseHead;
        while(temp2!=NULL){
            if(temp1->val != temp2->val)
            return false;
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
};