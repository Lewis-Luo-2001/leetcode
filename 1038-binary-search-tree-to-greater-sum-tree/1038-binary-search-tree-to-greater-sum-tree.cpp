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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> values;
        
        retrieveValues(root, values);
        updateNodes(root, values);

        return root;
    }

    void retrieveValues(TreeNode* root, vector<int>& values) {
        if(!root) return;

        values.push_back(root -> val);

        retrieveValues(root -> left, values);
        retrieveValues(root -> right, values);
    }

    void updateNodes(TreeNode* root, vector<int>& values) {
        if(!root) return;

        int addition = 0;
        for(int i = 0; i < values.size(); i++) {
            addition += (values[i] > root -> val) ? values[i] : 0;
        }
        root -> val += addition;

        updateNodes(root -> left, values);
        updateNodes(root -> right, values);
    }
};