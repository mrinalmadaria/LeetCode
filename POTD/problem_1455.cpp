#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string s, string sW) {
        string a = "";
        int cnt = 1;

        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])) a += s[i];
            else{
                a = "";
                cnt++;
            }
            if(a.substr(0, sW.size()) == sW) return cnt;
        }
        return -1;
    }
};