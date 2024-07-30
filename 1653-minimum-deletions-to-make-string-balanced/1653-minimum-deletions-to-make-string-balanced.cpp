class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.size();

        vector<int> prefixSumA(N, 0), prefixSumB(N, 0);

        int countA = 0, countB = 0;
        for(int i = 0; i < N; i++) {
            prefixSumA[N - i - 1] = countA;
            prefixSumB[i] = countB;

            countA += (s[N - i - 1] == 'a');
            countB += (s[i] == 'b');
        }

        int ans = N;
        for(int i = 0; i < N; i++) {
            ans = min(ans, prefixSumA[i] + prefixSumB[i]);
        }
        return ans;
    }
};

// 12233344
// 00112334

// aaabb