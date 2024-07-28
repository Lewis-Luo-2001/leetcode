class Solution {
private:
    vector<vector<int>> matrix;
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // find the shortest path with doing bfs
        queue<int> q({n - 1});
        vector<int> d(n, INT_MAX);
        d[n - 1] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == INT_MAX) {
                    d[nei] = d[cur] + 1;
                    q.push(nei);
                }
            }
        }

        // distance of the second shortest path can only be (d + 1) or (d + 2)
        int len = d[0] + 2;
        q.push(0);
        bool done = false;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto nei : adj[cur]) {
                if (d[nei] == d[cur]) {
                    len--;
                    done = true;
                    break;
                } else if (d[nei] == d[cur] - 1) {
                    q.push(nei);
                }
            }
            if(done) break;
        }

        int curTime = 0;
        for (int i = 0; i < len; i++) {
			if ((curTime / change) % 2 == 1)  // have to wait until the signal turns into green
                curTime = ((curTime / change) + 1) * change;    
            curTime += time;
        }
        return curTime;
    }
};
