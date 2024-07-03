class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1, count = 3;

        while(left < right && count > 0) {
            if(nums[left + 1] - nums[left] >= nums[right] - nums[right - 1]) {
                left++;
            }
            else {
                right--;
            }

            count--;
        }

        return nums[right] - nums[left];
    }
};