class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int x=0;
        
        for(int i=1;i<n;i++)
        {
            x+=abs(s[i]-s[i-1]);
        }
        return x;
        
    }
};