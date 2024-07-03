class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        int maxi=sum;
        int l=k-1;
        int r=n-1;
        while(l>=0&&r>=n-k)
        {
            sum=sum-cardPoints[l];
            l--;
            sum=sum+cardPoints[r];
            r--;
            maxi=max(sum,maxi);
            
        }
        return maxi;
        
        
    }
};