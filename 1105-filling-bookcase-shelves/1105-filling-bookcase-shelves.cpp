class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        const int N = books.size();
        vector<int> dp(N + 1);
        dp[0] = 0;

        for(int i = 0; i < N; ++i){
            int width = books[i][0];
            int height = books[i][1];
            dp[i + 1] = dp[i] + height;

            for(int j = i - 1; j >= 0 && width + books[j][0] <= shelfWidth; --j){
                height = max(height, books[j][1]);
                width += books[j][0];
                dp[i + 1] = min(dp[i + 1], height + dp[j]);
            }
        }

        return dp[N];
    }
};