class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> hashTable;
        vector<int> ret;
        ret.resize(2);
        //��ʼ����ϣ��
        for(int i = 0; i<numbers.size(); ++i)
        {
            hashTable[numbers[i]] = i;
        }
        
        //ѭ������
        for(int i = 0; i<hashTable.size(); ++i)
        {
            //���������һ������
            int ANumber = target-numbers[i];
            if(hashTable[ANumber] && hashTable[ANumber] > i)
            {
                ret[0] = i+1;
                ret[1] = hashTable[ANumber]+1;
                break;
            }
        }
        return ret;
    }
};