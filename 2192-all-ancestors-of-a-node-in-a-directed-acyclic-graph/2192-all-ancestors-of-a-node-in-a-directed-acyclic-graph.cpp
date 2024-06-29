class Solution {
private:
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> hash;
    vector<int> visited;

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // reverse the edges, and bfs/dfs each nodes
        // the nodes in the path is the ancestors

        ans = vector<vector<int>>(n);

        // build the reversed hash
        for(int i = 0; i < edges.size(); i++) {
            hash[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++) {
            visited = vector<int>(n);
            dfs(i, i);
        }

        for(int i = 0; i < n; i++) {
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

    void dfs(int root, int current) {
        if(visited[current]) return;

        visited[current] = 1;

        if(root != current) {
            ans[root].push_back(current);
        }

        for(int i = 0; i < hash[current].size(); i++) {
            dfs(root, hash[current][i]);
        }
    }
};