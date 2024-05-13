class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int currentcount=1;
        int longest=1;
        int lastsmaller=INT_MIN;
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==lastsmaller)
            {
                currentcount++;
                lastsmaller=nums[i];
                
            }
            else if(nums[i]!=lastsmaller)
            {
                lastsmaller=nums[i];
                currentcount=1;
            }
            longest=max(longest,currentcount);
            
        }
        return longest;
        
    }
};