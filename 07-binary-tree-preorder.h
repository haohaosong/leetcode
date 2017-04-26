/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) 
    {
    	vector<int> v;
        if(root == NULL)
            return v;
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty())
        {
            while(cur)
            {
                v.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = s.top();
            cur = top->right;
            s.pop();
        }
        return v;
    }
};