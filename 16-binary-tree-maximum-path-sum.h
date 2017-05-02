/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//��ĿҪ��
//	��������е�һ��·��
//	��·���ϵĺ�Ϊ����·���е����ֵ
//	��·�����Ծ����κε������ڵ㣨���׽ڵ���ӽڵ㣩
//	��·�����Բ��������ڵ�
//���������
//	�ݹ�ʱ�������������
//	1�����·��������ǰ���ڵ㣬�Լ����Һ��ӽڵ㣨�൱�ں��ýڵ��γɵ�·����
//	2�����·��������ǰ���ڵ��Լ���ǰ�ڵ��������
//	3�����·��������ǰ���ڵ��Լ�������ǰ�ڵ��������
//����˼·��
//	��Ҫ��������maxPath����������·��ֵ��ͨ���Ƚϣ����Ըı�����·��maxPath
//	�ֱ��󾭹����Ӻ;����Һ��ӵ�·�����ֵ
//ע�⣺
//	Ӧ��ʼ��ΪINT_MIN����ʾ���ε���Сֵ
//	�����ķ���ֵΪ������ǰ���ڵ��·��
//	��maxPath������·�������ֵ
class Solution {
public:
    //����ֵ�����ڵ��ֵ�����亢���ϵ�·����ȡ���ӵ�·�����Һ���·���Ľϴ��ߣ�
    int _maxPathSum(TreeNode* root, int& maxPath)
    {
        if(root == NULL)
            return 0;
        
        //�󾭹����Ӻ;����Һ��ӵ�·����ֵ
        int leftPathSum = max(0,_maxPathSum(root->left,maxPath));
        int rightPathSum = max(0,_maxPathSum(root->right,maxPath));
        
        //maxPath�ĸı䣬��Ҫ�ȽϾ�����統ǰ���ڵ�Ĵ�С��֮ǰ��������·���ĳ��ȵĴ�С
        maxPath = max(leftPathSum+rightPathSum+root->val,maxPath);
        
        //����ֵ�����ڵ��ֵ�����亢���ϵ�·����ȡ���ӵ�·�����Һ���·���Ľϴ��ߣ�
        return max(leftPathSum,rightPathSum)+root->val;
    }
    
    int maxPathSum(TreeNode *root) {
        int maxPath = INT_MIN;
        _maxPathSum(root,maxPath);
        
        return maxPath;
    }
};