/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-11-30 21:43:03
 	Problem       : problem
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

class Stack {
	queue<int> Q;
public:
    // Push element x onto stack.
    void push(int x) {
        Q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int l = Q.size();
        if(l == 0) return ; 
        for(int i = 0; i < l-1; i++){
        	int tmp = Q.front();
        	Q.pop();
        	Q.push(tmp);
        }
        Q.pop();
    }

    // Get the top element.
    int top() {
        int l = Q.size(), tmp;
        if(l == 0) return NULL;
        for(int i = 0; i < l; i++){
        	tmp = Q.front();
        	Q.pop();
        	Q.push(tmp);
        }
        return tmp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.empty();
    }
};
