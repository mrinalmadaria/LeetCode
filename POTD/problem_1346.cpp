#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int i : arr){
            if(mp[2*i] || (!(i & 1) && mp[i / 2])){
                return true;
            }
            mp[i]++;
        }
        return false;
    }
};