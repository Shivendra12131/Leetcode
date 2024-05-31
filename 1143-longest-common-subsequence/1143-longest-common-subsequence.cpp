class Solution {
private:
    int longestCommonSubsequence(string& text1, string& text2, int n, int m, vector<vector<int>>& dp) {
        //memoization 
//         if (n == 0 || m == 0) return 0;
//         if (dp[n][m] != -1) return dp[n][m];

//         if (text1[n-1] == text2[m-1]) {
//             dp[n][m] = 1 + longestCommonSubsequence(text1, text2, n-1, m-1, dp);
//         } else {
//             dp[n][m] = max(longestCommonSubsequence(text1, text2, n-1, m, dp), 
//                            longestCommonSubsequence(text1, text2, n, m-1, dp));
//         }
//         return dp[n][m];
//     }
        
        //top down approach
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                // agr dono same hai to i-1 aur j-1 call karna padega
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    // nhi same hai to 2 call hoga aur dono ka max le lenge hm
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[n][m];     
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //initialisation for top down approach
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        
        return longestCommonSubsequence(text1, text2, n, m, dp);
    }
};
