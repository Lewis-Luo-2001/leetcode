class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary serch rows
        int l = 0, r = matrix.size() - 1, mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(target == matrix[mid][0]) return true;
            else if(target < matrix[mid][0]) r = mid - 1;
            else if(target > matrix[mid][0]) l = mid + 1;
        }

        // binary search in the row
        int row = l - 1;
        if(row < 0) return false;
        
        l = 0, r = matrix[0].size() - 1;
        while(l <= r) {
            mid = (l + r) / 2;
            if(target == matrix[row][mid]) return true;
            else if(target < matrix[row][mid]) r = mid - 1;
            else if(target > matrix[row][mid]) l = mid + 1;
        }
        return false;
    }
};