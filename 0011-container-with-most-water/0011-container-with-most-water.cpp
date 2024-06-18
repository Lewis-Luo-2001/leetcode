class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0, sum = 0;

        while(left < right) {
            sum = min(height[left], height[right]) * (right - left);
            ans = max(ans, sum);

            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};

// [1,8,6,2,5,4,8,3,7]
//  ^               ^ -> 7
//    ^             ^ -> 49