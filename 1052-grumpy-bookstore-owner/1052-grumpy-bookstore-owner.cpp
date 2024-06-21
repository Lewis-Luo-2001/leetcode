class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int N = customers.size();
        int satisfied = 0;

        for(int i = 0; i < N; i++) {
            satisfied += (grumpy[i]) ? 0 : customers[i];
        }

        int left = 0, right = minutes, unsatisfied = 0, maxAdd;
        for(int i = left; i < right; i++) {
            unsatisfied += (grumpy[i]) ? customers[i] : 0;
        }
        maxAdd = unsatisfied;

        while(right < N) {
            unsatisfied -= (grumpy[left]) ? customers[left] : 0;
            unsatisfied += (grumpy[right]) ? customers[right] : 0;

            maxAdd = max(unsatisfied, maxAdd);

            left++, right++;
        }

        return satisfied + maxAdd;
    }
};

// 1 0 1 2 1 1 7 5
// 0 1 0 1 0 1 0 1

// 1. sum the satisfied customers whithout using the minutes
// 2. use a fixed-size window to find the window which can make the most satisfied customers