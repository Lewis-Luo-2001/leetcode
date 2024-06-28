class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> counter(n, 0);
        priority_queue<int> pq;

        for(int i = 0; i < roads.size(); i++) {
            counter[roads[i][0]]++;
            counter[roads[i][1]]++;
        }

        for(int i = 0; i < n; i++) {
            pq.push(counter[i]);
        }

        long long ans = 0;
        while(!pq.empty()) {
            ans += pq.top() * (long long)n--;
            pq.pop();
        }

        return ans;
    }
};

// 1. use a priority queue to record the road num of each city
// 2. add the sum