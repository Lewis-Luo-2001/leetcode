class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int N = nums.size();

        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hash;
        for(int i = 0; i < N; i++) {
            hash[nums[i]]++;
        }

        for(auto e : hash) {
            pq.push(pair<int, int>(e.second, e.first));
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};