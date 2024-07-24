class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int N = nums.size();

        vector<vector<int>> pairs;
        for(int i = 0; i < N; i++) {
            int mul = 1, mappedNum = 0, num = nums[i];
            while(num > 0) {
                mappedNum += mul * mapping[(num % 10)];

                mul *= 10;
                num /= 10;
            }
            if(nums[i] == 0) mappedNum = mapping[0];
            pairs.push_back({mappedNum, i, nums[i]});
        }

        sort(pairs.begin(), pairs.end());

        vector<int> ans;

        for(auto p : pairs) {
            ans.push_back(p[2]);
        }

        return ans;
    }
};