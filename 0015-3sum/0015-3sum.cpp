class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        int i, j, k;
        for(i = 0; i < N; i++) {
            int target = -1 * nums[i];

            // 2sum
            j = i + 1, k = N - 1;
            while(j < k) {
                if(i == j) {
                    j++;
                    continue;
                }
                if(i == k) {
                    k--;
                    continue;
                }

                int sum = nums[j] + nums[k];

                if(sum < target) j++;
                else if(sum > target) k--;
                else {
                    vector<int> v({nums[i], nums[j], nums[k]});
                    ans.push_back(v);

                    // avoid duplicate num 2
                    while (j < k && nums[j] == v[1]) j++;
                    // avoid duplicate num 3
                    while (j < k && nums[k] == v[2]) k--;
                }
            }
            
            // avoid duplicate num 1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }

        return ans;
    }
};