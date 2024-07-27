class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int NO_PATH_LEN = 1000000;
        long long totalCost = 0;

        /* dp : want to build the shortest path cost matrix from any alphabet to other any alphabet
             a b c ... x y z
           a 
           b
           c
           .
           .
           .
           x
           y
           z
        */
        vector<vector<int>> dp(26, vector<int>(26, NO_PATH_LEN));

        // fisrt, build the dp matrix as adjacency matrix
        for(int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a', to = changed[i] - 'a';
            dp[from][to] = min(dp[from][to], cost[i]);
        }

        // setup the diagonal
        for(int i = 0; i < 26; i++) {
            dp[i][i] = 0;
        }

        // then apply the Floyd Warshall algorithm to build the shortest path matrix
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        for(int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a', to = target[i] - 'a';
            if(dp[from][to] == NO_PATH_LEN) return -1;
            totalCost += dp[from][to];
        }

        return totalCost;
    }
};