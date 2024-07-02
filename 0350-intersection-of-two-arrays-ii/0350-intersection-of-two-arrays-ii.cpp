class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans;
        unordered_map<int,int>mpp1;
        int j=0;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++)
        {
            mpp1[nums1[i]]++;
        }
        while(j<m)
        {
            if(mpp1[nums2[j]]>0)
            {
                ans.push_back(nums2[j]);
                mpp1[nums2[j]]--;
            }
            j++;
        }
        return ans;
        
    }
};