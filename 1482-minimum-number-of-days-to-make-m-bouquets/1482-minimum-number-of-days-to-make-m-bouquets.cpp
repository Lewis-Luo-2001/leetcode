class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int N = bloomDay.size();
        int bloomMax = 0;
        for(int day : bloomDay) {
            bloomMax = max(bloomMax, day);
        }

        if((long long)m * k > N) return -1;

        int left = 0, right = bloomMax, mid, ans = INT_MAX;
        while(left <= right) {
            mid = (left + right) / 2;
            if(isValidDays(mid, bloomDay, m, k)) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    bool isValidDays(int days, vector<int>& bloomDay, int m, int k) {
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            int targetIndex = i + k - 1;
            for(int j = i; j <= targetIndex && j < bloomDay.size(); j++) {
                if(bloomDay[j] > days) {
                    break;
                }
                else {
                    if(j >= targetIndex) bouquets++;
                }
                i = j;
            }

            if(bouquets >= m) return true;
        }

        return false;
    }
};