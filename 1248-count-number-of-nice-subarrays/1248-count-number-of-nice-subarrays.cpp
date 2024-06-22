class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> isOdd(N, 0);
        for(int i = 0; i < N; i++) {
            isOdd[i] = nums[i] % 2 != 0;
        }

        // sliding window
        int left = 0, right = 0, ans = 0, odd = 0, count = 0;
        while(right < N) {

            if(isOdd[right]){
                odd++;
                
                if(odd >= k) {
                    count = 1;
                    while (!(isOdd[left++])) count++;
                    ans += count;
                }
            }
            else if(odd >= k) ans += count;

            right++;
        }

        return ans;
    }
};
