class Solution {
public:
    int minInsertions(string s) {
      string b=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        int m=n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int plength=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                if(s[i-1]==b[j-1])
                {
                    
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return n-dp[n][m];
    }
};