#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> myMap;

        for(int i = 0; i < n; i++){
            myMap[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for(int i = 0; i < n; i++){
            names[i] = myMap[heights[i]];
        }

        return names;
    }
};