/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-03-09 22:11:51
 	Problem       : sort list using merge
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


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        //search mid
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p2->next && p2->next->next) {
        	p1 = p1->next;
        	p2 = p2->next->next;
        } 
        ListNode *mid = p1->next;
        p1->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        //merge two sorted list
        ListNode ret = ListNode(0);
        ListNode *last = &ret;
        while(l1 != NULL && l2 != NULL) {
        	if(l1->val < l2->val) {
        		last->next = l1;
        		l1 = l1->next;
        	}
        	else {
        		last->next = l2;
        		l2 = l2->next;
        	}
        	last = last->next;
        }
        if(l1) last->next = l1;
        if(l2) last->next = l2;
        return ret.next;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}