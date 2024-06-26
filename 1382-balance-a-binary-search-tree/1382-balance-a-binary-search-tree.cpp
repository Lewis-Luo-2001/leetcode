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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        int numNode = 0;
        
        getValues(root, values);

        return buildBST(0, values.size() - 1, values);
    }

    void getValues(TreeNode* root, vector<int>& values) {
        if(!root) return;

        // LVR traverse, so the array `values` will be sorted
        getValues(root -> left, values);
        values.push_back(root->val);
        getValues(root -> right, values);
    }

    TreeNode* buildBST(int left, int right, vector<int>& values) {
        if(left > right) return NULL;
        int mid = (left + right) / 2;

        TreeNode* node = new TreeNode(values[mid]);
        node -> left = buildBST(left, mid - 1, values);
        node -> right = buildBST(mid + 1, right, values);

        return node;
    }
};