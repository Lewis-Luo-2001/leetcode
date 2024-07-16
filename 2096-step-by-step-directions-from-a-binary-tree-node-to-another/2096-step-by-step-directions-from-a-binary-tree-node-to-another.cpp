/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path1, path2;
        
        dfs(root, startValue, path1);
        dfs(root, destValue, path2);

        while(path1.size() > 0 && path2.size() > 0 && path1[0] == path2[0]) {
            path1.erase(0, 1);
            path2.erase(0, 1);
        }

        for(char &c : path1) {
            c = 'U';
        }

        return path1 + path2;
    }

    bool dfs(TreeNode* root, int targetValue, string& path) {
        if(!root) return false;

        if(root -> val == targetValue) return true;

        path += "L";
        if(dfs(root -> left, targetValue, path)) {
            return true;
        }
        path.pop_back();

        path += "R";
        if(dfs(root -> right, targetValue, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};

// 5 -> 1 -> 3
// 5 -> 2 -> 6
