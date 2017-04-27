class Solution {
public:
    int candy(vector<int> &ratings) {
        int childNum = ratings.size();
        
        if(childNum == 1)
            return 1;
        
        //初始化所有人的糖果为1
        vector<int> vCandy(childNum,1);
        
        //从左到右，保证一个方向上的满足
        for(int i = 1; i<childNum; i++)
        {
            if(ratings[i-1] < ratings[i])
            {
                vCandy[i] = vCandy[i-1]+1;
            }
        }
        
        //从右到左，保证另一个方向满足条件
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