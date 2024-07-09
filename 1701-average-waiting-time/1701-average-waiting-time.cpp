class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int N = customers.size();

        double totalTime = 0, curTime = 0;

        for(int i = 0; i < N; i++) {
            curTime = max(curTime, (double)customers[i][0]) + customers[i][1];
            totalTime += curTime - customers[i][0];
        }

        return (double)totalTime / N;
    }
};