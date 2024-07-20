class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int N = rowSum.size(), M = colSum.size();
        vector<vector<int>> matrix(N, vector<int>(M, 0));

        for(int col = 0; col < M; col++) {
            matrix[0][col] = colSum[col];
        }

        for(int row = 1; row < N; row++) {
            int sum = rowSum[row];
            for(int col = 0; col < M; col++) {
                if(matrix[0][col] <= 0) continue;
                else if (sum > matrix[0][col]) {
                    sum -= matrix[0][col];
                    matrix[row][col] += matrix[0][col];
                    matrix[0][col] = 0;
                }
                else {
                    matrix[0][col] -= sum;
                    matrix[row][col] += sum;
                    break;
                }
            }
        }

        return matrix;
    }
};