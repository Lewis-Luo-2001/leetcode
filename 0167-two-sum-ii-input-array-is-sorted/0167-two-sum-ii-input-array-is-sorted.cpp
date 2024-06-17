class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum < target) {
                left++;
            }
            else if(sum > target) {
                right--;
            }
            else {
                return {left + 1, right + 1};
            }
        }

        return {left + 1, right + 1};
    }
};