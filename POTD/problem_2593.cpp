#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sortedNums(n); 
        
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        
        sort(sortedNums.begin(), sortedNums.end());
        
        long long score = 0;

        for (int i = 0; i < n; i++) {
            int num = sortedNums[i].first;
            int idx = sortedNums[i].second;
            
            if (nums[idx] != -1) {
                score += num;
                nums[idx] = -1;
                if (idx > 0) {
                    nums[idx - 1] = -1;
                }
                if (idx < n - 1) {
                    nums[idx + 1] = -1;
                }
            }
        }
        
        return score;
    }
};