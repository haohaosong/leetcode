#include<iostream>
using namespace std;

/*
* author:haohaosong
* date:2017/4/18
* note:第一题-求二叉树的最小深度
*/

class Solution {
public:
	//递归查找最小深度
	//root当前节点，depth，当前的深度，minDepth是最小深度，并传入引用，代表可修改
    void _run(TreeNode* root,int depth,int& minDepth)
    {
    	if(root == NULL)
            return;
		
		//判断是否为叶子节点
        bool isLeaf = (root->left == NULL) && (root->right == NULL);
        if(isLeaf)
        {
			//注意：minDepth为0的时候也需要修改
            if(minDepth == 0 || depth<minDepth)
                minDepth = depth;
            return;
        }
		
		//递归遍历
        _run(root->left,depth+1,minDepth);
        _run(root->right,depth+1,minDepth);
    }
	//求最小深度
    int run(TreeNode *root) 
    {
        int depth = 0;
        int minDepth = 0;
        _run(root,depth+1,minDepth);
    	return minDepth;
    }
};