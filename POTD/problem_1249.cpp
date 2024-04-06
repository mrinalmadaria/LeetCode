#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0, flag = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
                flag++;
            } else if (c == ')' && flag > 0) {
                close++;
                flag--;
            }
        }
        
        int k = std::min(open, close);
        std::string ans = "";
        open = k;
        close = k;
        for (char c : s) {
            if (c == '(') {
                if (open > 0) {
                    ans += '(';
                    open--;
                }
                continue;
            }
            if (c == ')') {
                if (close > 0 && close > open) {
                    ans += ')';
                    close--;
                }
                continue;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};