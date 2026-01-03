class Solution {
public:
    int maxsubarraysum(vector<int> nums){
         int res=nums[0];
         int maxending=nums[0];
        for(int i=1; i<nums.size(); i++){
            maxending=max(maxending+nums[i],nums[i]);
            res=max(res,maxending);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalsum=maxsubarraysum(nums);
        if(normalsum<0)
            return normalsum;
        int arrsum=0;
        for(int i=0; i<nums.size(); i++){
            arrsum += nums[i];
            nums[i]=-nums[i];
        }
        int circular_sum = arrsum + maxsubarraysum(nums);
        int ans=max(circular_sum,normalsum);
        return ans;
    }
};
