class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        unordered_set<int> mods;
        int sum = 0, r = 0;

        for(int i = 0; i < N; i++) {
            sum += nums[i];
            int mod = sum % k;
            if(mods.count(mod)) return true;
            mods.insert(r);
            r = mod;
        }

        return false;
    }
};

// (presum[j]-presum[i]+nums[i]) mod k == 0
// (presum[j]-presum[i-1]) mod k == 0
// presum[j] mod k == presum[i-1] mod k

// [1,2,12]
// [1,3,15]
// [3,3]