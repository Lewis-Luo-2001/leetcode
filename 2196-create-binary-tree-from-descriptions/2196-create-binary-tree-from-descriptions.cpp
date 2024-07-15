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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // <val<ptr, parentPtr>>
        unordered_map<int, pair<TreeNode*, TreeNode*>> hash;
        TreeNode* root = nullptr;

        for(int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
            TreeNode *parentPtr = hash[parent].first, *childPtr = hash[child].first;

            if(parentPtr == nullptr) {
                parentPtr = new TreeNode(parent);
                hash[parent].first = parentPtr;
                hash[parent].second = nullptr;
            }

            if(childPtr == nullptr) {
                childPtr = new TreeNode(child);
                hash[child].first = childPtr;
            }
            hash[child].second = parentPtr;

            if(isLeft) {
                parentPtr -> left = childPtr;
            }
            else {
                parentPtr -> right = childPtr;
            }

            if(root == nullptr) {
                root = parentPtr;
            }
        }

        while(hash[root -> val].second != nullptr) {
            root = hash[root -> val].second;
        }

        return root;
    }
};