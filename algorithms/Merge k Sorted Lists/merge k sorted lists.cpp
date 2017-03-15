/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-03-08 22:15:22
 	Problem       : merge k sorted lists using heap (priority_queue)
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
 
class Solution {
	struct node {
		int val;
		ListNode *p;
		node(int x, ListNode * y):val(x), p(y){}
		friend bool operator<(node x, node y) {
			return x.val > y.val;
		}	
	};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<node> Q;
        ListNode ret = ListNode(0);
        ListNode *last = &ret;
        for(int i = 0; i < lists.size(); i++) {
        	if(lists[i] == NULL) continue;
        	Q.push(node(lists[i]->val, lists[i]));
        }
        while(!Q.empty()) {
        	node now = Q.top();
        	Q.pop();
        	last->next = now.p;
        	last = last->next;
        	if(now.p->next == NULL) continue;
        	Q.push(node(now.p->next->val, now.p->next));
        }
        return ret.next;
    }
};

