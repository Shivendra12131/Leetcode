class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int cnt = 0;
        int presum = 0;
        mpp[0]=1;

        for (auto it : nums) {
            presum += it;
            // Check if presum equals k
            // if (presum == k) {
            //     cnt++;
            // }
            // Increment count if presum - k exists in the map
            cnt += mpp[presum - k];
            mpp[presum]++;
        }

        return cnt;
    }
};
