#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0}; // Only one node, return the root
        }
        
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }
        
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;
            
            for (int i = 0; i < size; i++) {
                int leaf = q.front();
                q.pop();
                for (int neighbor : graph[leaf]) {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};