#pragma once

/*
* author:haohaosong
* date:2017/4/24
* note:1-2-3-4转换成1-4-2-3
*/

#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//奇数的话，返回中间节点，偶数的话，返回中间节点的下一个
	//然后将两部分断开
	ListNode* findMidNode(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* pSlow = head;
		ListNode* pFast = head;
		ListNode* pPrev = NULL;
		while (pFast && pFast->next)
		{
			pPrev = pSlow;
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}

		pPrev->next = NULL;
		return pSlow;
	}

	//翻转后面的链表
	ListNode* reorderRightList(ListNode* head)
	{
		ListNode* pCur = head;
		ListNode* pPrev = NULL;
		ListNode* pNewHead = NULL;
		while (pCur)
		{
			ListNode* pNext = pCur->next;

			if (pNext == NULL)
				pNewHead = pCur;

			pCur->next = pPrev;
			pPrev = pCur;
			pCur = pNext;
		}
		return pNewHead;
	}

	ListNode* mergeList(ListNode* pLeft, ListNode* pRight)
	{
		ListNode* newHead = pLeft;

		ListNode* pLeftCur = pLeft;
		ListNode* pRightCur = pRight;

		while (pLeftCur && pRightCur)
		{
			ListNode* pLeftNext = pLeftCur->next;
			ListNode* pRightNext = pRightCur->next;

			pLeftCur->next = pRightCur;

			if (pLeftNext)
				pRightCur->next = pLeftNext;

			pLeftCur = pLeftNext;
			pRightCur = pRightNext;
		}

		return newHead;
	}

	void reorderList(ListNode* &head)
	{
		ListNode* rightListHead = findMidNode(head);//找到并分开左右部分的链表
		rightListHead = reorderRightList(rightListHead);
		head = mergeList(head, rightListHead);
	}
};