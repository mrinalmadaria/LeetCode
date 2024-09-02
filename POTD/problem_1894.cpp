#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalkNeeded = 0;

        for(int chalkUse : chalk){
            totalChalkNeeded += chalkUse;
        }

        int remainingChalk = k % totalChalkNeeded;

        for(int i = 0; i < chalk.size(); i++){
            if(remainingChalk < chalk[i]){
                return i;
            }
            remainingChalk -= chalk[i];
        }
        return 0;
    }
};