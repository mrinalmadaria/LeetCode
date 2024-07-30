#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for(char ch : s){
            if(ch == 'b'){
                count++;
            }else if(count){
                res++;
                count--;
            }
        }
        return res;
    }
};