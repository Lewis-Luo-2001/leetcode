class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> count;

        for(int i = 0; i < edges.size(); i++) {
            if(count[edges[i][0]]++ > 0) return edges[i][0];
            if(count[edges[i][1]]++ > 0) return edges[i][1];
        }

        return 0;
    }
};