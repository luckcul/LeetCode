/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-21 09:27:32
 	Problem       : Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
    	ListNode tmp;
        ListNode *ret = &tmp;
        ret->next = head;
        ListNode *last, *p1, *p2;
        last = ret;
        while(last) {
        	p1 = last->next;
        	if(!p1) break;
        	p2 = p1->next;
        	if(!p2) break;
        	ListNode *p2Next = p2->next;
        	last->next = p2;
        	p2->next = p1;
        	p1->next = p2Next;
        	last = p1;
        }
        return ret->next;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}