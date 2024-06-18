class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        vector<int> leftMax(N, INT_MIN), rightMax(N, INT_MIN);

        int curMax = INT_MIN;
        for(int i = 0; i < N; i++) {
            curMax = max(curMax, height[i]);
            leftMax[i] = curMax;
        }

        curMax = INT_MIN;
        for(int i = N - 1; i >= 0; i--) {
            curMax = max(curMax, height[i]);
            rightMax[i] = curMax;
        }

        int ans = 0;
        for(int i = 1; i < N - 1; i++) {
            ans += max(0, min(leftMax[i - 1], rightMax[i + 1]) - height[i]);
        }

        return ans;
    }
};

// intuition: the water trapped in index i = min(left highest, right highest) - height[i]
// steps:
// 1. construct 2 vector (leftMax and rightMax)
//      leftMax[i] represents the height of the highest bar in [0, i]
//      rightMax[i] represents the height of the highest bar in [i, N)
// 2. then the water trapped in index i = max(0, min(leftMax[i - 1], rightMax[i + 1]) - height[i])