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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        if (!root) return result;
        while (myQueue.size() > 0){
            vector<int> lvl;
            int length = (int)myQueue.size();
            for (int i = 0; i < length; i++){
                TreeNode * node = myQueue.front();
                myQueue.pop();
                if (i + 1 == length)
                    result.push_back(node->val);
                if (node->left) myQueue.push(node->left);
                if (node->right) myQueue.push(node->right);
            }
            // result.push_back(lvl);
        }
        return result;
        
        
        
    }
};
