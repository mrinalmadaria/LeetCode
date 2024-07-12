#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount = 0, bCount = 0, lesser = min(x, y), result = 0;

        for(char ch : s){
            if(ch > 'b'){
                result += min(aCount, bCount) * lesser;
                aCount = 0, bCount = 0;
            }else if(ch == 'a'){
                if(x < y && bCount > 0){
                    bCount--;
                    result += y;
                }else{
                    aCount++;
                }
            }else{
                if(x > y && aCount > 0){
                    aCount--;
                    result += x;
                }else{
                    bCount++;
                }
            }
        }
        result += min(aCount, bCount) * lesser;
        return result;
    }
};