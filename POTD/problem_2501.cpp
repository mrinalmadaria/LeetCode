#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mp;
        sort(nums.begin(), nums.end());
        int res = -1;

        for(int num : nums){
            int squareRoot = sqrt(num);
            if(squareRoot * sqrt(num) == num && mp.find(squareRoot) != mp.end()){
                mp[num] = mp[squareRoot] + 1;
                res = max(res, mp[num]);
            }else{
                mp[num] = 1;
            }
        }

        return res;
    }
};