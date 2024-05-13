class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)//insert elements into the set
        {
            st.insert(nums[i]);
        }
        int longest=1;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
//this is the starting point har baar starting point alag hoga naye elements ke liey
            {
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end())
//set me find karo jo o(1) leta hai find karne me 
                {
                    cnt++;
                    x=x+1;
                }
                longest=max(longest,cnt);
                
            }
            
            
        }
        return longest;
        
        
    }
};