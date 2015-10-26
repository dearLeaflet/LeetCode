/*
寻找两个链表的最早公共节点

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
					↘
					c1 → c2 → c3
					↗
B:		b1 → b2 → b3
begin to intersect at node c1.
遍历链表的长度，通链表长度差值确定起始比较位置
*/
#include"lib.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int x = 0, y = 0;
		ListNode *p = headA, *q = headB;
		while (p){
			++x;
			p = p->next;
		}

		while (q){
			++y;
			q = q->next;
		}

		p = headA, q = headB;
		if (x > y){
			int dist = x - y;
			while (dist--){
				p = p->next;
			}
		}
		if (x < y){
			int dist = y - x;
			while (dist--){
				q = q->next;
			}
		}

		while (p != q){
			p = p->next;
			q = q->next;
		}
		return q ? q : NULL;
	}
};