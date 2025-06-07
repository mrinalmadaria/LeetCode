#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> freq(26);
        int a = 'a';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!freq[j].empty()) {
                        freq[j].pop_back();
                        break;
                    }
                }
            } else {
                freq[s[i] - a].push_back(i);
            }
        }

        vector<bool> keep(s.size(), false);
        for (const auto& stack : freq) {
            for (int idx : stack) {
                keep[idx] = true;
            }
        }

        string result;
        for (int i = 0; i < s.size(); i++) {
            if (keep[i]) result += s[i];
        }
        return result;
    }
};