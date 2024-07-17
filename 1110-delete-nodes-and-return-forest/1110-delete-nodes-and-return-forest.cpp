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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        vector<TreeNode*> roots;
        vector<bool> hash(1001, false);
        
        for(int n : toDelete) {
            hash[n] = true;
        }

        dfs(root, hash, roots, true);

        return roots;
    }

    void dfs(TreeNode* &root, vector<bool>& hash, vector<TreeNode*>& roots, bool isRoot) {
        if(root == nullptr) return;

        dfs(root -> left, hash, roots, hash[root -> val]);
        dfs(root -> right, hash, roots, hash[root -> val]);

        if(!hash[root -> val] && isRoot) roots.push_back(root);
        if(hash[root -> val]) root = nullptr;
    }
};