#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int res = INT_MAX;
    
            int face[7] = {};
            for(int i = 0; i < tops.size(); i++) {
                face[tops[i]]++;
                if(bottoms[i] != tops[i]) face[bottoms[i]]++;
            }
    
            // for each possible face from 1...6
            for(int x = 1; x <= 6; x++) {
                if(face[x] < tops.size()) continue;      // can't fill entire row
    
                int maintainTop = 0, maintainBottom = 0;
                bool possible = true;
    
                // count flips
                for(int i = 0; i < tops.size(); i++) {
                    if (tops[i] != x && bottoms[i] != x) {
                        possible = false; 
                        break;
                    }
                    if (tops[i] != x)      maintainTop++;
                    if (bottoms[i] != x)   maintainBottom++;
                }
    
                if (possible) 
                    res = min(res, min(maintainTop, maintainBottom));
            }
    
            return res == INT_MAX ? -1 : res;
        }
    };