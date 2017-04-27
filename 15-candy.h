class Solution {
public:
    int candy(vector<int> &ratings) {
        int childNum = ratings.size();
        
        if(childNum == 1)
            return 1;
        
        //��ʼ�������˵��ǹ�Ϊ1
        vector<int> vCandy(childNum,1);
        
        //�����ң���֤һ�������ϵ�����
        for(int i = 1; i<childNum; i++)
        {
            if(ratings[i-1] < ratings[i])
            {
                vCandy[i] = vCandy[i-1]+1;
            }
        }
        
        //���ҵ��󣬱�֤��һ��������������
        for(int i = childNum-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1] && vCandy[i] <= vCandy[i+1])
            {
                vCandy[i] = vCandy[i+1]+1;
            }
        }
        
        int sumCandy = 0;
        for(int i = 0; i<childNum; ++i)
        {
            sumCandy += vCandy[i];
        }
        
        return sumCandy;
    }
};