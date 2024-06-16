class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long i = 0, maxSum = 0, count = 0;

        while(maxSum < n) {
            if(i < nums.size() && nums[i] <= maxSum + 1) {
                maxSum = maxSum + nums[i];
                i++;
            }
            else {
                maxSum = maxSum * 2 + 1;
                count++;
            }
        }

        return count;
    }
};


// [1,5,10]
// i = 0, nums[i] = 1, maxSum = 1
// nums[1] > maxSum + 1 = 2 , -> count++, add 2 -> maxSum += 2, maxSum = 3
// nums[1] > maxSum + 1 = 4 , -> count++, add 4 -> maxSum += 4, maxSum = 7
// nums[1] < maxSum + 1 = 8 , -> i++, maxSum += nums[1], maxSum = 13