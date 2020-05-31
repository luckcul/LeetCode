class Solution {
public:
    double getProbability(vector<int>& balls) {
        double dp[10][30][10][10]; 
        memset(dp, 0, sizeof(dp)); 
        int tot_ball = 0; 
        int tot_col = balls.size(); 
        for(int i = 0; i < balls.size(); i++) {
            tot_ball += balls[i]; 
        }
        double c[50][50]; 
        for(int i = 0; i < 50; i++) {
            c[i][0] = c[i][i] = 1; 
            for(int j = 1; j < i; j++) {
                c[i][j] = c[i-1][j] + c[i-1][j-1];
            }
        }
        
        double acc_cnt = 0; 
        dp[0][0][0][0] = 1; 
        for(int col_idx = 1; col_idx <= balls.size(); col_idx++) {
            int ball_cnt = balls[col_idx-1]; // 颜色下球数量
            acc_cnt += ball_cnt; 
            
            for(int i = 0; i <= ball_cnt; i++) { // 第一块放多少该颜色的球
                for(int j = 0; j <= tot_ball/2; j++) { // 第一块累计占用多少
                    if(j-i<0) continue;
                    if(acc_cnt-j > tot_ball/2) continue; 
                    int last_j = j-i;
                    for(int col_1 = 0; col_1 <= tot_col; col_1++) { // 第一块多少不同颜色
                        int last_col_1 = (i == 0 ? col_1:col_1-1); 
                        if(last_col_1 < 0) continue; 
                        for(int col_2 = 0; col_2 <= tot_col; col_2++) { // 第二块多少不同颜色
                            int last_col_2 = (ball_cnt-i == 0 ? col_2:col_2-1); 
                            if(last_col_2 < 0) continue; 
                            int a_up = i; 
                            int b_up = ball_cnt - i; 
                            int a_down = tot_ball/2 - last_j; 
                            int b_down = tot_ball/2 - (acc_cnt-ball_cnt-last_j); 
                            // int fa = fac[a_down]/(fac[a_up] * fac[a_down-a_up]); 
                            // int fb = fac[b_down]/(fac[b_up] * fac[b_down-b_up]); 
                            
                            dp[col_idx][j][col_1][col_2] += dp[col_idx-1][last_j][last_col_1][last_col_2] * c[a_down][a_up] * c[b_down][b_up]; 
                        }
                    }
                }
            }
        }
        double tot = 0; 
        double right = 0; 
        for(int i=1; i<= tot_col; i++) {
            for(int j = 1; j <= tot_col; j++) {
                tot += dp[tot_col][tot_ball/2][i][j]; 
                if(i==j) right += dp[tot_col][tot_ball/2][i][j]; 
            }
        }
        // cout<<tot<<endl;
        // cout<<right<<endl;
        return right*1.0 / tot; 
    }
};