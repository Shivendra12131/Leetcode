class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int x=0;
        int i=0;
        int j=0;
        
        while(i<n&&j<m){
            x=j;
            while(j<m)
            {
                if(s[i]==t[j])
                {
                    i++;
                    j++;
                    x=j;
                }
                else{
                    j++;
                }
            }
            
        }
        if(i==n) return true;
        return false;
    }
};