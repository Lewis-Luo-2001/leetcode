class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int N = names.size();
        vector<pair<int, string>> people;

        for(int i = 0; i < N; i++) {
            people.push_back({heights[i], names[i]});
        }

        sort(people.begin(), people.end());

        vector<string> ans;
        for(int i = N - 1; i >= 0; i--) {
            ans.push_back(people[i].second);
        }

        return ans;
    }
};