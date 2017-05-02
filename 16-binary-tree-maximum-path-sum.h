/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//题目要求：
//	求二叉树中的一条路径
//	该路径上的和为所有路径中的最大值
//	该路径可以经过任何的连续节点（父亲节点和子节点）
//	该路径可以不经过根节点
//情况分析：
//	递归时，有以下情况。
//	1、最大路径经过当前根节点，以及左右孩子节点（相当于横跨该节点形成的路径）
//	2、最大路径经过当前根节点以及当前节点的左子树
//	3、最大路径经过当前根节点以及经过当前节点的右子树
//解题思路：
//	需要传入引用maxPath，保存最大的路径值，通过比较，可以改变最大的路径maxPath
//	分别求经过左孩子和经过右孩子的路径最大值
//注意：
//	应初始化为INT_MIN，表示整形的最小值
//	函数的返回值为经过当前根节点的路径
//	用maxPath保存了路径的最大值
class Solution {
public:
    //返回值：根节点的值加上其孩子上的路径（取左孩子的路径和右孩子路径的较大者）
    int _maxPathSum(TreeNode* root, int& maxPath)
    {
        if(root == NULL)
            return 0;
        
        //求经过左孩子和经过右孩子的路径大值
        int leftPathSum = max(0,_maxPathSum(root->left,maxPath));
        int rightPathSum = max(0,_maxPathSum(root->right,maxPath));
        
        //maxPath的改变，需要比较经过横跨当前根节点的大小和之前保存的最大路劲的长度的大小
        maxPath = max(leftPathSum+rightPathSum+root->val,maxPath);
        
        //返回值：根节点的值加上其孩子上的路径（取左孩子的路径和右孩子路径的较大者）
        return max(leftPathSum,rightPathSum)+root->val;
    }
    
    int maxPathSum(TreeNode *root) {
        int maxPath = INT_MIN;
        _maxPathSum(root,maxPath);
        
        return maxPath;
    }
};