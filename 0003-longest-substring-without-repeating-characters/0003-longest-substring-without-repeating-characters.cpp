class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;  // start of the current window

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the current character is found in the map and its index is within the current window
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            // Move the start to the right of the previous occurrence of the current character
            start = charIndexMap[currentChar] + 1;
        }

        // Update the index of the current character
        charIndexMap[currentChar] = end;

        // Update the maximum length of the substring found so far
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
    }
};