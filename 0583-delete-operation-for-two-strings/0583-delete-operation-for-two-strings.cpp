class Solution {
    // Approach->
    //     as it is asking minimum number of operation to convert the string as it is asking for otpimal as well as it is based on string so we can think it is variation of lcs
    // Step1->we will find the longest common subseqeunce between a and b and then 
    //         step 2-> length of word1-length of lcs +length of word2-length of lcs 
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans=(n-dp[n][m])+(m-dp[n][m]);
        return ans;
        
        
    }
};