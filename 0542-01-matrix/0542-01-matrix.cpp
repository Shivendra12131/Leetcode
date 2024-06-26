class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>distt(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                
            }
        }
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            distt[row][col]=dist;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                  vis[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return distt;
        
    }
};