class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]){
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;
    }
};

// 1 1 2 2 3 7 
//   2 2 2 3 7 
//     3 2 3 7 
//       4 3 7 
//         5 7 
//           7 