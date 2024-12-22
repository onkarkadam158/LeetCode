class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int curr=(j-i+1);
                if(l<=curr and curr<=r and sum>0) res=min(res,sum);
            }
        }
        return res==INT_MAX ? -1:res;
    }
};