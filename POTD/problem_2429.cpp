#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(unsigned num1, unsigned num2) {
        int B=popcount(num2), A=popcount(num1);
        bitset<31> y=num1, x=0;
        if (A>B){
            for (int b=30; B>=1 && b>=0; b--){
                if (y[b]){
                    x[b]=1;
                    B--;
                }
            }
            return x.to_ulong();
        }
        else{
            B-=A;
            for (int b=0; B>=1 && b<31; b++){
                if (y[b]==0){
                    y[b]=1;
                    B--;
                }
            }
            return y.to_ulong();
        }
    }
};