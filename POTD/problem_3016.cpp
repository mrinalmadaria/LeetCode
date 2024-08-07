#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(auto &c){
        for(int x : c) cout<<x<<", ";
        cout<<endl;
    }

    int minimumPushes(string word) {
        int freq[26] = {0};

        for(char c : word){
            freq[c - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());

        int sz = 0, push = 1, ans = 0;
        for(; sz<26 && freq[sz]!=0; sz++){
            if (sz>=8 && sz%8==0) push++;
            ans+=freq[sz]*push;    
        }
        return ans;
    }
};