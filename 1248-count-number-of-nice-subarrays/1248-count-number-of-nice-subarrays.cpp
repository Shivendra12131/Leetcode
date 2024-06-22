class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&1)==1) nums[i]=1;
            else{
                nums[i]=0;
            }
        }
    
  int prefix_sum=0;
        map<int,int>mpp;
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            int check=prefix_sum-k;
            if(mpp.find(check)!=mpp.end())
            {
                cnt+=mpp[check];
            }
            mpp[prefix_sum]++;
            
        }
    
   
       return cnt; 
    }
};