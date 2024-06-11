class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hash;
        vector<int> ans;
        for(int e : arr1) {
            hash[e]++;
        }
        for(int e : arr2) {
            for(int i=0; i<hash[e]; ++i) {
                ans.push_back(e);
            }
            hash[e] = 0;
        }
        for(auto &e : hash) {
            for(int i=0; i<e.second; ++i) {
                ans.push_back(e.first);
            }
        }

        return ans;
    }
};