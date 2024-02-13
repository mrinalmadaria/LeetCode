#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s = i;
            reverse(s.begin(), s.end());
            if(s==i) return s;
        }
        return "";
    }
};