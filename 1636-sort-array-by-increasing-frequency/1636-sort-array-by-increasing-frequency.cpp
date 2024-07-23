class Solution {
private:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counter;

        for(int num : nums) {
            counter[num]++;
        }

        vector<pair<int, int>> pairs;
        for(auto element : counter) {
            pairs.push_back({element.second, element.first});
        }

        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = 0; j < pairs[i].first; j++)
                ans.push_back(pairs[i].second);
        }

        return ans;
    }
};