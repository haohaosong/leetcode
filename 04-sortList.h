#pragma once

/*
* author:haohaosong
* date:2017/4/19
* note:����Ĺ鲢����
*/

class Solution {
public:
	//�ҵ��м�Ľڵ�
	ListNode* findMiddleNode(ListNode* head)
	{
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}

	//���������������ϳ������һ������
	ListNode* mergeTwoList(ListNode* phead1, ListNode* phead2)
	{
		if (phead1 == NULL)
			return phead2;
		if (phead2 == NULL)
			return phead1;

		ListNode* newHead = NULL;
		if (phead1->val < phead2->val)
			newHead = phead1;
		else
			newHead = phead2;

		ListNode* cur1 = phead1;
		ListNode* cur2 = phead2;
		ListNode* prev1 = NULL;
		ListNode* prev2 = NULL;

		while (cur1 && cur2)
		{
			while (cur1 && cur1->val < cur2->val)
			{
				prev1 = cur1;
				cur1 = cur1->next;
			}

			//�ж�ͷָ����1����2
			if (prev1)
				prev1->next = cur2;

			//���cur1Ϊ�գ���������
			if (cur1 == NULL)
				break;

			while (cur2 && cur2->val < cur1->val)
			{
				prev2 = cur2;
				cur2 = cur2->next;
			}

			prev2->next = cur1;
		}

		if (cur1 == NULL)
			prev1->next = cur2;
		else
			prev2->next = cur1;

		return newHead;
	}

	ListNode *sortList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* midNode = findMiddleNode(head);
		ListNode* midNext = midNode->next;
		midNode->next = NULL;

		ListNode* right = sortList(midNext);


		ListNode* left = sortList(head);

		return mergeTwoList(left, right);
	}
};