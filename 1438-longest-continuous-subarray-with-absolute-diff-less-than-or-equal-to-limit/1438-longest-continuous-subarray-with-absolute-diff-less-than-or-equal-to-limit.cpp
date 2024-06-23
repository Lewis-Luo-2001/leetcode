class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minD, maxD;
        int left = 0, right = 0, ans = 0;

        while(right < nums.size()) {
            while (!maxD.empty() && nums[maxD.back()] <= nums[right]) {
                maxD.pop_back();
            }
            maxD.push_back(right);

            while (!minD.empty() && nums[minD.back()] >= nums[right]) {
                minD.pop_back();
            }
            minD.push_back(right);

            while (!maxD.empty() && !minD.empty() && nums[maxD.front()] - nums[minD.front()] > limit) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};

// 8 2 4 7
// 