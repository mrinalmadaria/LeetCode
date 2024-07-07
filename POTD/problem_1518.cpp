#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int cur_empty = numBottles;

        while (cur_empty / numExchange != 0) {
            int full_drinked = cur_empty / numExchange;
            int left_empty = cur_empty - full_drinked * numExchange;
            res += full_drinked;
            cur_empty = left_empty + full_drinked;
        }
        return res;
    }
};