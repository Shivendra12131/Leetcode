class Solution {
public:

int lower_bound(vector<int>&nums,int target)
{
    int n=nums.size();

    int l=0;
    
    int h=n-1;
    while(l<=h)
    {
        int mid=l-(l-h)/2;
        if(nums[mid]<target)
        {
            l=mid+1;
        }
        else{
            h=mid-1;
        }

    }
    return l;
}
    vector<int> searchRange(vector<int>& nums, int target) {
     int n=nums.size();
     // hm log isme 2 index store karenge aur lower bound wala function call  kar denge jaise 
     //1 value mil gya target ke liye ab second value ke liye target+1n kar doo jo index mile usme se 1 minus kar doo
     int index1=lower_bound(nums,target);
     int index2=lower_bound(nums,target+1)-1;
    if(index1<nums.size()&& nums[index1]==target)
    {
        return {index1,index2};
    }
    return {-1,-1};



    }
};