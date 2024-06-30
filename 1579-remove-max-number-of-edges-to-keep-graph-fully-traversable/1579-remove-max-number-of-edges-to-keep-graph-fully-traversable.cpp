class Solution {
public:
    vector<int> bob, alice;
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for (int i = 0; i <= n; ++i) {
            bob.push_back(i);
            alice.push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[0] > b[0];
        });
        int ans = 0;
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (!merge(e[1], e[2], alice))
                    ans++;
            }
            else if (e[0] == 2) {
                if (!merge(e[1], e[2], bob))
                    ans++;
            }
            else {
                merge(e[1], e[2], alice);
                if (!merge(e[1], e[2], bob))
                    ans++;
            }
        }
        int a = find(alice.back(), alice), b = find(bob.back(), bob);
        for (int i = 1; i < n; ++i) {
            if (a != find(alice[i], alice) or b != find(bob[i], bob))
                return -1;
        }
        return ans;
    }
    int find(int i, vector<int>& g) {
        return g[i] == i ? i : g[i] = find(g[i], g);
    }
    bool merge(int a, int b, vector<int>& g) {
        a = find(a, g);
        b = find(b, g);
        if (a == b)
            return false;
        g[b] = a;
        return true;
    }
};