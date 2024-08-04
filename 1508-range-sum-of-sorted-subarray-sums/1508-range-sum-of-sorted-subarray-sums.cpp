class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MODULO = 1e9 + 7;

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        vector<int> subSums;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(i == 0) subSums.push_back(prefixSum[j]);
                else subSums.push_back(prefixSum[j] - prefixSum[i - 1]);
            }
        }

        sort(subSums.begin(), subSums.end());

        int ans = 0;
        for(int i = left - 1; i < right; i++) {
            ans = (ans + subSums[i]) % MODULO;
        }

        return ans;
    }
};

// 00, 01, 02, 03
// 11, 12, 13
// 22, 23,
// 33