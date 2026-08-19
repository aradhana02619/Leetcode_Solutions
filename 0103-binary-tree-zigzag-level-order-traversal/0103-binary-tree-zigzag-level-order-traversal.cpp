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
//  Approach 1 Using Queue
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>>ans;

//         if(root==nullptr){
//     return ans;
// }
// queue<TreeNode*>q;
// q.push(root);

// bool leftToRight = true;
// while(!q.empty()){
//     int size = q.size();
// vector<int>level;
// for(int i=0; i<size; i++){
//     TreeNode* node = q.front();
//     q.pop();
//     level.push_back(node->val);

//     if(node->left)
//       q.push(node->left);

//      if(node->right)
//       q.push(node->right);

// }
// if(!leftToRight)
//    reverse(level.begin(), level.end());
//    ans.push_back(level);
//    leftToRight = !leftToRight;
// }
// return ans;

//     }
// };

// approach 2 using double ended queue

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);

        bool leftToRight = true;

        while (!dq.empty()) {

            int n = dq.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {

                if (leftToRight) {

                    TreeNode* node = dq.front();
                    dq.pop_front();

                    level.push_back(node->val);

                    if (node->left)
                        dq.push_back(node->left);

                    if (node->right)
                        dq.push_back(node->right);
                }

                else {

                    TreeNode* node = dq.back();
                    dq.pop_back();

                    level.push_back(node->val);

                    if (node->right)
                        dq.push_front(node->right);

                    if (node->left)
                        dq.push_front(node->left);
                }
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};