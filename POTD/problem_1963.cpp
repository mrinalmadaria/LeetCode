#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;

        for(const char &ch : s){
            if(ch == ']'){
                if(imbalance == 0){
                    imbalance++;
                }else{
                    imbalance--;
                }
            }else{
                imbalance++;
            }
        }
        return (imbalance + 1) / 2;
    }
};