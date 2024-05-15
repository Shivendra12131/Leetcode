class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            cnt+=mpp[nums[i]-k]+mpp[nums[i]+k];
            mpp[nums[i]]++;
            
        }
        return cnt;
        
    }
};