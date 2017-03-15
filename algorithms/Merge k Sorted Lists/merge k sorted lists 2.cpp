/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-03-09 09:20:14
 	Problem       : merge k sorted lists using merge.
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
	
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int size = lists.size();
    	if(size == 0) return NULL;
    	else if(size == 1) return lists[0];

		int m = size / 2;  
		vector<ListNode*> lists1(lists.begin(), lists.begin()+m);
		vector<ListNode*> lists2(lists.begin()+m, lists.end());
		ListNode *p1 = mergeKLists(lists1);
		ListNode *p2 = mergeKLists(lists2);
		ListNode ret = ListNode(0);
		ListNode *last = &ret;
		while(p1 != NULL && p2 !=NULL) {
			if(p1->val < p2->val) {
				last->next = p1;
				p1 = p1->next;
			}
			else {
				last->next = p2;
				p2 = p2->next;
			}
			last = last->next;
		}
		if(p1) {
			last->next = p1;
		}
		if(p2) {
			last->next = p2;
		}
		return ret.next;
    }
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}