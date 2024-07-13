class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;
        int j=cardPoints.size()-1;
        int maxi=0;
        
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
        {
            maxi+=cardPoints[i];
            
        }
        int l=k-1;
        int r=n-1;
        int maximumpoints=maxi;
        while(k--)
        {
            maxi=maxi-cardPoints[l];
            l--;
            // maximumpoints=max(maximumpoints,maxi);
            maxi=maxi+cardPoints[r];
              maximumpoints=max(maximumpoints,maxi);
            r--;
            
            
        }
        return maximumpoints;
    }
};