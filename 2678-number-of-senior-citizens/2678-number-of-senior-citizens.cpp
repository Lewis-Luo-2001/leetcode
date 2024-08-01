class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string& detail : details) {
            ans += detail.substr(11, 2) > "60";
        }
        return ans;
    }
};