#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int index = 0;

        while (tickets[k] != 0) {
            if (tickets[index] > 0) {
                count++;
                tickets[index]--;
                index = (index + 1) % tickets.size();
            } else if (tickets[index] == 0) {
                index = (index + 1) % tickets.size();
            }
        }
        
        return count;
    }
};