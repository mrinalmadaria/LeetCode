#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < (1<<n); i++){
            int subsetXOR = 0;
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    subsetXOR ^= nums[j];
                }
            }
            totalSum += subsetXOR;
        }
        return totalSum;
    }
};