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
typedef long long LL; 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> count(citations.size()+1, 0);
        int length = citations.size();
        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= length) count[length] ++;
            else count[citations[i]]++;
        }
        int sum = 0;
        for(int i = length; i >= 0; i--) {
            sum += count[i];
            if(sum >= i) return i;
        }
    }
};
int main() {
    cout<<"hello"<<endl;
}