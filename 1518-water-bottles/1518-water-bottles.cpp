class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, empty = 0;
        while(numBottles > 0) {
            ans += numBottles;
            int total = empty + numBottles;
            numBottles = total / numExchange;
            empty = total % numExchange;
        }

        return ans;
    }
};