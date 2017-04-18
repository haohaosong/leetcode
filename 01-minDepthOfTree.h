#include<iostream>
using namespace std;

/*
* author:haohaosong
* date:2017/4/18
* note:��һ��-�����������С���
*/

class Solution {
public:
	//�ݹ������С���
	//root��ǰ�ڵ㣬depth����ǰ����ȣ�minDepth����С��ȣ����������ã�������޸�
    void _run(TreeNode* root,int depth,int& minDepth)
    {
    	if(root == NULL)
            return;
		
		//�ж��Ƿ�ΪҶ�ӽڵ�
        bool isLeaf = (root->left == NULL) && (root->right == NULL);
        if(isLeaf)
        {
			//ע�⣺minDepthΪ0��ʱ��Ҳ��Ҫ�޸�
            if(minDepth == 0 || depth<minDepth)
                minDepth = depth;
            return;
        }
		
		//�ݹ����
        _run(root->left,depth+1,minDepth);
        _run(root->right,depth+1,minDepth);
    }
	//����С���
    int run(TreeNode *root) 
    {
        int depth = 0;
        int minDepth = 0;
        _run(root,depth+1,minDepth);
    	return minDepth;
    }
};