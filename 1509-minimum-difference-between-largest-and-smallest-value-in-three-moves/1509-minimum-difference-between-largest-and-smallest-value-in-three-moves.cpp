class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 3) return 0;

        sort(nums.begin(), nums.end());

        return min({nums[N - 4] - nums[0], nums[N - 3] - nums[1], nums[N - 2] - nums[2], nums[N - 1] - nums[3]});
    }
};
