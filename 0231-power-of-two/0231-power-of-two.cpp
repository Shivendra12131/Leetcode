class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        int i=0;
        if(n==1) return true;
        if(n==0 || n<0) return false;
        while(n>0)
        {
            if((n&1)) cnt++;
            
            n=(n>>1);
        
        }


        if(cnt>1) return false;
        return true;
    }
};