/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-11-30 22:21:12
 	Problem       : problem
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

class Queue {
	stack<int> Stack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        Stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        int l = Stack.size();
        stack<int> S;
        for(int i = 0; i < l; i++) {
        	int tmp = Stack.top();
        	Stack.pop();
        	S.push(tmp);
        }
        S.pop();
        for(int i = 0; i < l-1; i++){
        	int tmp = S.top();
        	S.pop();
        	Stack.push(tmp);
        }
    }

    // Get the front element.
    int peek(void) {
        int l = Stack.size();
        stack<int> S;
        for(int i = 0; i < l; i ++) {
        	int tmp = Stack.top();
        	Stack.pop();
        	S.push(tmp);
        }
        int ret = S.top();
        for(int i = 0; i < l; i++){
        	int tmp = S.top();
        	S.pop();
        	Stack.push(tmp);
        }
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return Stack.empty();
    }
};
