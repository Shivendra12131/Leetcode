class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        int cntfresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntfresh++;
            }
        }
        int tm=0;
        int cnt=0;
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        
        while(!q.empty())
        {
      
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++)
            {
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                  vis[nrow][ncol]==0&&grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
                
            }
        }
        if(cnt!=cntfresh) return -1;
        return tm;
    }
};