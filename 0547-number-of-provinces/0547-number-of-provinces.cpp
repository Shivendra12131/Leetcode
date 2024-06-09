// in this question i will use dfs for every starting node starting node can be 1,2,3,.... 
// i will use visited arrray for getting track the node which i have traversed earlier and for every node i traversed called (dfs )  i will make it visited so that starting node can be not same again and again 
// adjacennct matrix is given i can use adjacency list as well as adjanceny matrix 


class Solution {
    private:
    void dfs(vector<vector<int>>&isConnected,vector<int>&vis,int node)
    {
        vis[node]=1;
        for(int j=0;j<isConnected.size();j++)
        {
            if(!vis[j]&&isConnected[node][j]==1)
            {
                dfs(isConnected,vis,j);
            }
        }
        
    }
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(isConnected,vis,i);
            }
        }
        
        return cnt;
        
    }
};