// GOAL: find the maximum possible integer `minForce`

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        const int N = position.size();

        // 1. Sort the vector `position`
        sort(position.begin(), position.end());

        // 2. Binary search the the max `minForce` bwtween 0 to `position[N-1]` - `position[0]`
        int left = position[0], right = position[N-1], mid, ans = INT_MIN;
        while(left <= right) {
            mid = (left + right) / 2;

            if(isValidMinForce(mid, position, m)) {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    bool isValidMinForce(int minForce, vector<int>& position, int m) {
        int placed = 0, pre = position[0] - minForce;
        
        for(int i = 0; i < position.size(); i++) {
            if(position[i] - pre >= minForce) {
                placed++;
                pre = position[i];
            }

            if(placed >= m) return true;
        }

        return false;
    }
};