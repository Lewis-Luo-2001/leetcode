class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                ans++;
                for(int j = i; j < i + k; j++) {
                    if(j >= nums.size()) return -1;
                    nums[j] = (nums[j] == 0) ? 1 : 0;
                }
            }
        }

        return ans;
    }
};
