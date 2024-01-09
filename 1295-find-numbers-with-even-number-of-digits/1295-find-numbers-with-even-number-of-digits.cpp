class Solution {
public:
    int digit(int a) {
        int cnt = 0;
        if(a==0) return 1;
        while(a != 0) {
            a/=10;
            ++cnt;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(digit(nums[i])%2 == 0) {
                count++;
            }
        }
        return count;
    }
};