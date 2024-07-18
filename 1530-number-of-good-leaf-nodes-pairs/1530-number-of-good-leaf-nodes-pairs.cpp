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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance, int& ans) {
        vector<int> leave;
        if(root == nullptr) return {};

        vector<int> left = dfs(root -> left, distance, ans);
        vector<int> right = dfs(root -> right, distance, ans);

        if(left.size() == 0 && right.size() == 0){
            leave.push_back(1);
            return leave;
        } 

        for(int i = 0; i < left.size(); i++){
            for(int j = 0; j < right.size(); j++){
                if(left[i] + right[j] <= distance){
                    ans++;
                }
            }
        }

        for(int i = 0; i < left.size(); i++){
            leave.push_back(left[i] + 1);
        }
          
        for(int i = 0; i < right.size(); i++){
            leave.push_back(right[i] + 1);
        }

        return leave;
    }
};