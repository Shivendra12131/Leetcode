class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] & 1) {  // Check if the number is odd
            cnt++;
            if (cnt == 3) return true;  // Check if we have three consecutive odds
        } else {
            cnt = 0;  // Reset count if an even number is encountered
        }
    }
    return false;  // Return false if no three consecutive odds are found
}
};