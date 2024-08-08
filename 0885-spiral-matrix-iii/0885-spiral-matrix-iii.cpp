class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // [right, down, left, up]
        int dir = 0, counter = 0, row = rStart, col = cStart, step = 0, stepCount = 0;

        vector<vector<int>> ans, visited(rows, vector<int>(cols, 0));
        
        while(counter < rows * cols) {
            if(row >= 0 && row < rows && col >= 0 && col < cols && visited[row][col] == 0) {
                ans.push_back({row, col});
                visited[row][col] = 1;
                counter++;
            }

            if((dir == 0 || dir == 2) && stepCount == 0) step++;

            if(dir == 0) col++;
            else if(dir == 1) row++;
            else if(dir == 2) col--;
            else if(dir == 3) row--;

            stepCount++;
            if(stepCount == step) {
                dir = (dir + 1) % 4;
                stepCount = 0;
            }
        }

        return ans;
    }
};