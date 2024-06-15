class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int N = profits.size();
        vector<pair<int, int>> p(N);
        for(int i = 0; i < N; i++) {
            p[i] = pair<int, int>(capital[i], profits[i]);
        }
        sort(p.begin(), p.end());
    
        int i = 0;
        priority_queue<int> maxCapital;
        while(k > 0) {
            while (i < N && p[i].first <= w) {
                maxCapital.push(p[i].second);
                i++;
            }
            if (maxCapital.empty()) break;
            w += maxCapital.top();
            maxCapital.pop();

            k--;
        }

        return w;
    }
};


// profits = [1,2,3], capital = [0,1,1]
// choose the max profit can be choosed