class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            vector<int> row(10, 0);
            vector<int> column(10, 0);
            for(int j=0; j<9; ++j){
                // check row
                if(board[i][j] != '.'){
                    if(row[board[i][j] - '0'] == 0) row[board[i][j] - '0'] = 1;
                    else return false;
                }
                
                // check column
                if(board[j][i] != '.'){
                    if(column[board[j][i] - '0'] == 0) column[board[j][i] - '0'] = 1;
                    else return false;
                }
            }
        }
        
        // check boxes
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                vector<int> box(10, 0);
                for(int k=0; k<9; ++k){
                    if(board[i*3 + k/3][j*3 + k%3] != '.'){
                        if(box[board[i*3 + k/3][j*3 + k%3] - '0'] == 0) box[board[i*3 + k/3][j*3 + k%3] - '0'] = 1;
                        else return false;
                    }
                }
            }
        }
        
        return true;
    }
};