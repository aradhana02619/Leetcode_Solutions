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
private:
    int matchingNodesCount = 0;
    pair<int, int> calculateSubtree(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        
        auto leftSubtree = calculateSubtree(root->left);
        auto rightSubtree = calculateSubtree(root->right);

       
        int currentSum = root->val + leftSubtree.first + rightSubtree.first;
        int currentCount = 1 + leftSubtree.second + rightSubtree.second;


        int average = currentSum / currentCount;

       
        if (root->val == average) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0; 
        calculateSubtree(root);
        return matchingNodesCount;

        
    }
};