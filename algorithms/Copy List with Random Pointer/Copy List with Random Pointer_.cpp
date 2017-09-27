/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-21 20:38:35
 	Problem       : Copy List with Random Pointer
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL) return NULL;
    	RandomListNode *p = head;
    	while(p) {
    		RandomListNode *temp = new RandomListNode(p->label);
    		temp->next = p->next;
    		p->next = temp;
    		p = temp->next;
    	}
    	p = head;
    	while(p) {
    		RandomListNode *newP = p->next;
    		RandomListNode *pRandom = p->random;
    		RandomListNode *newRandom = pRandom == NULL? NULL:pRandom->next;
    		newP->random = newRandom;
    		p = newP->next;
    	}
    	RandomListNode *newHead = head->next;
    	p = head;
    	while(p) {
    		RandomListNode *pNext = p->next->next;
    		if(pNext) p->next->next = pNext->next;
    		p->next = pNext;
    		p = p->next;
    	}
    	return newHead;
    }
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	RandomListNode p1 = RandomListNode(1);
	RandomListNode p2 = RandomListNode(2);
	p1.next = &p2;
	p1.random = &p2;
	p2.random = &p1;
	Solution x = Solution();
	x.copyRandomList(&p1);
	
	return 0; 
}