class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash1, hash2;
        for(int num : nums1) hash1[num]++;
        for(int num : nums2) hash2[num]++;

        vector<int> ans;
        for(auto e : hash1) {
            for(int i = 0; i < min(e.second, hash2[e.first]); i++) {
                ans.push_back(e.first);
            }
        }

        return ans;
    }
};