#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1, 0);

        minHeap.push({0, 1});

        while (!minHeap.empty()) {
            auto [timeTaken, node] = minHeap.top();
            minHeap.pop();

            freq[node]++;

            if (freq[node] == 2 && node == n) {
                return timeTaken;
            }

            for (auto neighbor : adj[node]) {
                int newTimeTaken = timeTaken;

                if ((newTimeTaken / change) % 2) {
                    newTimeTaken = change * (newTimeTaken / change + 1) + time;
                } else {
                    newTimeTaken = newTimeTaken + time;
                }

                if (dist1[neighbor] > newTimeTaken) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = newTimeTaken;
                    minHeap.push({newTimeTaken, neighbor});
                } else if (dist2[neighbor] > newTimeTaken && dist1[neighbor] != newTimeTaken) {
                    dist2[neighbor] = newTimeTaken;
                    minHeap.push({newTimeTaken, neighbor});
                }
            }
        }
        return 0;
    }
};