#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 199. Binary Tree Right Side View
// Use BFS. Search by layers, each time return the most right node in the next layer.
// Only push the nodes in the queue when finishing the search in a whole layer.

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            queue <TreeNode*> q;
            q.push(root);
            vector <int> ans;
            if(root == NULL) return ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                vector <TreeNode*> cur;
                while(!q.empty()){
                    TreeNode* curNode = q.front();
                    q.pop();
                    if(curNode->right != NULL) cur.push_back(curNode->right);
                    if(curNode->left != NULL) cur.push_back(curNode->left);
                }
                for(size_t i = 0;i < cur.size();i++) q.push(cur[i]);
            }
            return ans;
        }
    };