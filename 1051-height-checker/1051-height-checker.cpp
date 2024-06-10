class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101);
        for(int i = 0; i < heights.size(); i++) {
            count[heights[i]]++;
        }
        
        int ans = 0, j = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(j < count.size() && !count[j]) {
                j++;
            }
            ans += (heights[i] != j);
            count[j]--;
        }
        return ans;
    }
};