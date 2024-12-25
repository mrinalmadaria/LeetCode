#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int L = q.size();
            int M = INT_MIN;
            
            for (int i = 0; i < L; i++) {
                TreeNode* x = q.front();
                q.pop();
                
                M = max(M, x->val);
                
                if (x->left != nullptr) {
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    q.push(x->right);
                }
            }
            ans.push_back(M);
        }
        return ans;
    }
};