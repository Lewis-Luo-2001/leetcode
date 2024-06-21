class Solution {
public:
    bool isValidK(vector<int>& piles, int h, int k) {
        long long hour = 0;
        for(int i = 0; i < piles.size(); i++) {
            hour += ceil(piles[i] * 1.0 / k);
        }
        return hour <= h;
    }

    // find the valid k start from 1
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            maxPile = max(maxPile, piles[i]);
        }

        // O(lgM*N)
        int left = 1, right = maxPile, mid, k;
        while(left <= right) {
            mid = (left + right) / 2;

            if(isValidK(piles, h, mid)) {
                k = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return k;
    }
};