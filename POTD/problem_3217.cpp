#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *newHead = temp;

        while(temp->next){
            if(st.count(temp->next->val)){
                ListNode *d = temp->next;
                temp->next = temp->next->next;
                delete d;
            }else{
                temp = temp->next;
            }
        }

        return newHead->next;
    }
};