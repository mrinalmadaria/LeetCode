#include<bits/stdc++.h>
using namespace std;

using info = pair<int, int>; // (time, i*m+j)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m) { return i * m + j; }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1; // edge case

        const int n = grid.size(), m = grid[0].size(), N = 100000;
        int time[N];
        fill(time, time + n * m, INT_MAX);
        uint64_t pq[N];
        int back = 0;

        // Start at (0, 0) with time=0
        pq[back++] = 0;
        time[0] = 0;
        while (back > 0) {
            pop_heap(pq, pq + back, greater<>{});
            auto tij = pq[--back];
            int t = tij >> 32, ij = tij & ((1 << 30) - 1), i = ij / m,
                j = ij - i * m;

            //    cout<<" t="<<int(t)<<" i="<<int(i)<<" j="<<int(j)<<endl;
            // reach the destination
            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                // minimum time to reach (r, s)
                int w = ((grid[r][s] - t) & 1) ? 0 : 1;
                int nextTime =
                    max(t + 1, grid[r][s] + w); // backward if neccessary

                // update if this path having quicker time
                int rs=idx(r, s, m);
                if (nextTime < time[rs]) {
                    time[rs] = nextTime;
                    pq[back++] = ((uint64_t)nextTime << 32) + rs;
                    push_heap(pq, pq + back, greater<>{});
                }
            }
        }

        return -1; // never reach
    }
};