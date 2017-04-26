/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //step1:拷贝一份在原节点的后面
        RandomListNode* cur = head;
        while(cur)
        {
            RandomListNode* next = cur->next;
            RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = next;
            cur->next = newNode;
            cur = next;
        }
        
        //step2:将拷贝节点的随机指针指向原节点的下一个位置
        cur = head;
        while(cur)
        {
            RandomListNode* copyNode = cur->next;
            if(cur->random)
            	copyNode->random = cur->random->next;
        	cur = copyNode->next;
        }
        
        //step3:拆分
        cur = head;
        RandomListNode* newHead = NULL;
        RandomListNode* newCur = NULL;
        if(cur != NULL)
        {
            newHead = cur->next;
        	newCur = newHead;
        }   
        
        while(cur)
        {         
            newCur = cur->next;
            cur->next = newCur->next;
            cur = cur->next;
        }
        return newHead;
    }
};