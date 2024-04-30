#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        int mask = 0;
        count[0] = 1;
        long long result = 0;

        for(char ch : word){
            mask ^= 1 << (ch -'a');
            result += count[mask];

            for(int i = 0; i < 10; i++){
                result += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }
        return result;
    }
};