class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0; // If there are 4 or fewer elements, we can make all of them the same
        }

        sort(nums.begin(), nums.end());

        // We can make up to 3 changes, so we need to consider removing 3 elements from either end
        // Calculate the minimum difference for these 4 scenarios
        int minDiff = INT_MAX;
        minDiff = min(minDiff, nums[n-1] - nums[3]); // Remove the first 3 elements
        minDiff = min(minDiff, nums[n-2] - nums[2]); // Remove the first 2 and last 1 element
        minDiff = min(minDiff, nums[n-3] - nums[1]); // Remove the first 1 and last 2 elements
        minDiff = min(minDiff, nums[n-4] - nums[0]); // Remove the last 3 elements

        return minDiff;
    }
};