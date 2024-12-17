#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string repeatLimitedString(string& s, int k) {
        int freq[26] = {0};

        for (char c : s) 
            freq[c-'a']++;
        
        priority_queue<char> pq;
        for (int i=0; i<26; i++) {
            if (freq[i] > 0) 
                pq.emplace('a'+i);
        }
        
        string ans;
        ans.reserve(s.size());
                
        while (!pq.empty()) {
            char c=pq.top();
            pq.pop();
            
            int& f=freq[c-'a'];
            int use = min(f, k);
            ans.append(use, c);
            f-= use;

            if (f > 0) {
                if (pq.empty()) 
                    break;
                
                char c2= pq.top();
                ans.push_back(c2);
                int f2=--freq[c2-'a'];

                if (f2==0) pq.pop();

                pq.emplace(c);
            }
        }
        return ans;
    }
};