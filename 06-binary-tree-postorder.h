/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
   		vector<int> v;
        if(root == NULL)
            return v;
        
        stack<TreeNode*> s;
        TreeNode* cur = root;    
        TreeNode* prev = NULL;
        while(cur || !s.empty())
        {
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = s.top();
            //������Ϊ�ջ����������Ѿ������ʹ�
            if(top->right == NULL || top->right == prev)
            {
                v.push_back(top->val);
                prev = top;
                s.pop();
            }
            else
            {
                cur = top->right;
            }
        }
        return v;
    }
};