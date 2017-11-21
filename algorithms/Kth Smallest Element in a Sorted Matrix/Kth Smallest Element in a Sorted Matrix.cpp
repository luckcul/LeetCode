class Solution {
    struct node {
        int val, x, y;
        node(int v, int x_, int y_): val(v), x(x_), y(y_){}
        friend bool operator<(node a, node b) {
            return a.val > b.val;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        priority_queue<node> Q;
        Q.push(node(matrix[0][0], 0, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        int count = 0; 
        while(!Q.empty()) {
            node now = Q.top();
            Q.pop();
            count++;
            if(count >= k) return now.val;
            if(now.x+1 < n && vis[now.x+1][now.y] == false) Q.push(node(matrix[now.x+1][now.y], now.x+1, now.y)), vis[now.x+1][now.y] = true;
            if(now.y+1 < n && vis[now.x][now.y+1] == false) Q.push(node(matrix[now.x][now.y+1], now.x, now.y+1)), vis[now.x][now.y+1] = true;
        }
    }
};