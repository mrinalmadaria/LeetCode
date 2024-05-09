#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());

        int selected = 0;
        long long happinessScore = 0; 

        for (int score : happiness) {
            if (selected == k) {
                break;
            }
            happinessScore += std::max(0, score - selected);
            selected++;
        }
        return happinessScore;
    }
};