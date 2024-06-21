class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        int left = 0, right = N - 1, mid, ans = nums[0];

        while(left <= right) {
            mid = (left + right) / 2;
            
            if(nums[mid] < ans) {
                while(mid >= 0) {
                    if(nums[mid] > ans) return ans;
                    else {
                        ans = nums[mid];
                        mid--;
                    }
                }
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

// case 1: no rotate
// 1,2,3,4,5

// case 2: partial rotate
// 3,4,5,1,2

// case 3: fully rotate
// 5 4 3 2 1

// step1. assume the ans = nums[0]
// step2. binary search -> always drop the left half
//        if nums[mid] < ans -> update ans, also means the array is rotated -> start search the left part