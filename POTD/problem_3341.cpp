#include<bits/stdc++.h>
using namespace std;

// variant 
using int3 = pair<int, pair<int, int>>; // (time, i, j)
const static int d[5] = {0, 1, 0, -1, 0};
int Time[2500];
class Solution {
public:  
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    static int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        fill(Time, Time+n*m, INT_MAX);
        priority_queue<int3, vector<int3>, greater<int3>> pq;

        // Start at (0, 0) with time 0
        pq.emplace(0, make_pair(0, 0));
        Time[0] = 0;

        while (!pq.empty()) {
            auto [t, ij] = pq.top();
            auto [i, j]=ij;
            pq.pop();

            // reach the destination
            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;

                // minimum time to reach (r, s)
                int nextTime = max(t, moveTime[r][s]) + 1; // Wait if necessary

                // update if this path having quicker time
                const int rs=r*m+s;
                if (nextTime < Time[rs]) {
                    Time[rs] = nextTime;
                    pq.emplace(nextTime, make_pair(r, s));
                }
            }
        }

        return -1; // never reach
    }
};