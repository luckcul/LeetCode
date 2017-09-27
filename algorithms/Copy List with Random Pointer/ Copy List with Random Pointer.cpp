/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-21 13:50:51
 	Problem       :  Copy List with Random Pointer
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
	unordered_map<RandomListNode *, RandomListNode *> M;
	RandomListNode *getNewNode(RandomListNode *p){
		if(p == NULL) return NULL;
		if(M.find(p) == M.end()){
			RandomListNode *temp = (RandomListNode *)malloc(sizeof(RandomListNode));
			temp->label = p->label;
			M[p] = temp;
			cout<<temp<<endl;
			return temp;
		}
		else {
			cout<<M[p]<<endl;
			return M[p];
		}
	}
	RandomListNode *dfs(RandomListNode *p){
		if(p == NULL) return NULL;
		RandomListNode *ret = getNewNode(p);
		ret->random = getNewNode(p->random);
		ret->next = dfs(p->next);
		return ret;
	}
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	M.clear();
		return dfs(head);
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