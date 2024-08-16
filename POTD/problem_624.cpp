#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int result = 0;

        for (int i = 1; i < arrays.size(); ++i) {
 
            int localMin = arrays[i][0];
            int localMax = arrays[i].back();

          
            result = max(result, max(localMax - globalMin, globalMax - localMin));

            globalMin = min(globalMin, localMin);
            globalMax = max(globalMax, localMax);
        }

        return result;
    }
};