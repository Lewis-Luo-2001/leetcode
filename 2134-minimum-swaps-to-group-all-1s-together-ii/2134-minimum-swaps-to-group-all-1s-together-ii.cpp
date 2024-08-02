class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numOnes = 0, numZeros = 0, N = nums.size(), ans = N;
        for(int& num : nums) {
            if(num == 0) numZeros++;
            else numOnes++; 
        }

        if(numZeros == 0 || numOnes == 0) return 0;

        // no circular -> sliding window with 1
        int left = -1, right = numOnes - 1, curOnes = 0, curZeros;
        for(int i = 0; i < right; i++) {
            curOnes += (nums[i] == 1);
        }
        ans = min(ans, numOnes - curOnes);

        while(right < N) {
            if(left >= 0) curOnes -= nums[left++] == 1;
            else left++;
            curOnes += nums[right++] == 1;

            ans = min(ans, numOnes - curOnes);
        }

        // circular -> sliding window with 0
        left = -1, right = numZeros - 1, curZeros = 0;
        for(int i = 0; i < right; i++) {
            curZeros += (nums[i] == 0);
        }
        ans = min(ans, numZeros - curZeros);

        while(right < N) {
            if(left >= 0) curZeros -= nums[left++] == 0;
            else left++;
            curZeros += nums[right++] == 0;

            ans = min(ans, numZeros - curZeros);
        }

        return ans;
    }
};

// 0 1 0 1 1 0 0