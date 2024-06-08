#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<int> adj[], int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, it, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // Make an adjacency list
        vector<int> adj[n+1];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 ) {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<int> vis(n+1, 0);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(adj, i, vis);
            }
        }
        
        return cnt;
    }
};
