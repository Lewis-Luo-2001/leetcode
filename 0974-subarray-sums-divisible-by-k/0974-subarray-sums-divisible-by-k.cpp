class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> prefixSum(N, 0);
        int ans = 0;

        prefixSum[0] = nums[0];
        for(int i = 1; i < N; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        unordered_map<int, int> hash;
        for(int i = 0; i < N; i++) {
            int rem = prefixSum[i] % k;
            hash[rem < 0 ? (rem + k) : rem]++;
        }

        for(auto e : hash) {
            ans += (e.second) * (e.second - 1) / 2;
        }
        ans += hash[0];

        return ans;
    }
};

// prefixSumMod[i] = prefixSum[i] % k
// if hash[prefixSumMod[i]] is N 
//   -> if prefixSumMod[i] is not 0 -> form N(N-1)/2 subarray, C(N, 2) = N!/(2!)(N-2)! = N(N-1)/2
//   -> if prefixSumMod[i] is 0     -> form N subarray

// nums = [4,5,0,-2,-3,1], k = 5
// prefixSum = [4,9,9,7,4,5]
// prefixSumMod = [4,4,4,3,4,0]

// 2 -2 2 -4
// 2  0 2 -2