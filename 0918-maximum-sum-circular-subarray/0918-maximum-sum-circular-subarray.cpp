class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_nor = normalMaxSum(nums);
        if(max_nor < 0) {
            return max_nor;
        }
        int arr_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            arr_sum += nums[i];
            nums[i] =- nums[i];
        }
        int max_cir = arr_sum + normalMaxSum(nums);
        return max(max_nor, max_cir);
    }
    
    int normalMaxSum(vector<int> &nums) {
        int res = nums[0];
        int maxEnd = nums[0];
        for(int i=1; i<nums.size(); i++) {
            maxEnd = max(maxEnd + nums[i], nums[i]);
            res = max(res, maxEnd);
        }
        return res;
    }
};