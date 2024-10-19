#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }

        // Find the length of current string Sn
        int length = (1 << n) - 1;

        // Find the middle position
        int mid = length / 2 + 1;

        // If k is the middle position, return '1'
        if(k == mid){
            return '1';
        }

        // If k not in first half, find in remaining
        if(k < mid){
            return findKthBit(n - 1, k);
        }

        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};