class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int N = difficulty.size(), M = worker.size();

        vector<pair<int, int>> jobs;
        for(int i = 0; i < N; i++) {
            pair<int, int> p({profit[i], difficulty[i]});
            jobs.push_back(p);
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int jobId = N - 1, workerId = M - 1, ans = 0;
        while(jobId >= 0 && workerId >= 0) {
            if(worker[workerId] >= jobs[jobId].second) {
                ans += jobs[jobId].first;
                workerId--;
            }
            else {
                jobId--;
            }
        }

        return ans;
    }
};

// make vector<pair<int, int>>(difficulty, profit), sort it by the profit
// also sort the worker vector
// ex. difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// pair : [(2,10), (4,20), (6,30), (8,40), (10,50)], worker = [4,5,6,7]
// start from the index N(orM) - 1 to 0, maintain 2 indices, one records the index of the worker, 
// the other one records the index of the jobs