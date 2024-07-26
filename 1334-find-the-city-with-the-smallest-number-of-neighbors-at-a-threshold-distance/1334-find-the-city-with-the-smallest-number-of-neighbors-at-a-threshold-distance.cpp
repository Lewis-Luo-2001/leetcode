class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> adjMatrix(n, vector<long long>(n, INT_MAX));

        for(int i = 0; i < edges.size(); i++) {
            adjMatrix[edges[i][0]][edges[i][1]] = edges[i][2];
            adjMatrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        // apply Floyd-Warshall algorithm
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        int ans = INT_MIN, ansNumReachable = INT_MAX;
        for(int i = 0; i < n; i++) {
            int numReachable = 0;

            for(int j = 0; j < n; j++) {
                if(i != j && adjMatrix[i][j] <= distanceThreshold) numReachable++;
            }

            if(numReachable <= ansNumReachable) {
                ansNumReachable = numReachable;
                ans = max(ans, i);
            }
        }

        return ans;
    }
};
