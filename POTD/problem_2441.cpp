#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high){
            if((nums[low] + nums[high]) == 0){
                return nums[high];
            } else if((nums[low] + nums[high]) < 0){
                low++;
            } else {
                high--;
            }
        }
        return -1;
    }
};