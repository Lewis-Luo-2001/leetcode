class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26);

        for(int i = 0; i < word.size(); i++) {
            count[word[i] - 'a']++;
        }

        sort(count.begin(), count.end(), greater<int>());

        int ans = 0, i = 0;
        while(i < 26 && count[i] > 0) {
            ans += count[i] * (1 + (i / 8));
            i++;
        }

        return ans;
    }
};