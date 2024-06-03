class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int m=n;
        string b=s;
        reverse(s.begin(), s.end());
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
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
        return dp[n][m];
        
        
        
    }
};