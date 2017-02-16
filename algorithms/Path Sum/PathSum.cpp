/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-01-20 20:56:32
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

	bool flag; 
	void dfs(TreeNode* root, int sum) {
		if(flag) return ;
		if(root->left == NULL && root->right == NULL) {
			if(root->val == sum) flag = true;
			return ;
		}
		if(root->left != NULL) dfs(root->left, sum - root->val);
		if(root->right != NULL) dfs(root->right, sum - root->val);

	}
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	flag = false;
    	if(root != NULL) dfs(root, sum);
    	return flag;
    }
};
