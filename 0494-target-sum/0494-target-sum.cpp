class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
                int sum=accumulate(nums.begin(),nums.end(),0);
          int targetsum=(target+sum)/2;
        
        // If the (sum + target) is odd or target is out of the possible sum range, return 0
        if ((sum + target) % 2 != 0 || abs(target) > sum) {
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(targetsum+1,0));
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
      
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<targetsum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][targetsum];
        
    }
};