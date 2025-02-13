#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& a, int k) {
            priority_queue<int, vector<int>, greater<int>> q(a.begin(), a.end());
            for (int i = 0, x, y; ; ++i) {
                x = q.top();
                q.pop();
                if (x >= k) return i;
                y = q.top();
                q.pop();
                const long t = 2L * x + y; // test overflow
                q.push(t < k ? (int)t : k);
            }
            return -1;
        }
    };