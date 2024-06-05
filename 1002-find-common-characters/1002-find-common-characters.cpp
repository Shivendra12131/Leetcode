class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int>common(26,INT_MAX);

        for(int i = 0; i < words.size(); i++){

        vector<int>freq(26,0);  
        for(char ch:words[i]){
        freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++){
        common[i] = min(common[i],freq[i]);
        }
        
        }

        vector<string>ans;
        for(int i = 0; i < 26; i++){
        for(int j = 0; j < common[i]; j++){
        ans.push_back(string(1, 'a' + i));
        }
        }

    return ans;
    }
};

