#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        vector<pair<int, char>> v;
        string ans = "";

        for(auto ch : s){
            map[ch]++;
        }

        for(auto i : map){
            v.push_back({i.second, i.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        for(auto i : v){
            while(i.first--){
                ans += i.second;
            }
        }
        return ans;
    }
};