class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            ans.push_back(nums[nums[i]]);
        }
        
        return ans;
    }
};