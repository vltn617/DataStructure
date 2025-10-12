#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

int n;
string s0;
string s1;
int price[6];
int pairPrice[2];
int dp[2001][6][6][5];

void input(){
    cin >> n >> s0 >> s1;
    cin >> price[1] >> price[3] >> price[5];
    cin >> pairPrice[1];
    for (int i = 0; i < 2001; i++){
        for (int l = 0; l < 6; l++){
            for (int j = 0; j < 6; j++){
                for (int k = 0; k < 5; k++){
                    dp[i][l][j][k] = INT_MAX;
                }
            }
        }
    }
}

int dfs(int day, int r0, int r1, int p){
    if (day == n) return 0;
    if (dp[day][r0][r1][p] != INT_MAX) return dp[day][r0][r1][p];

    bool need_0, need_1;
    if (s0[day] == '0') need_0 = false;
    else need_0 = true;
    if (s1[day] == '0') need_1 = false;
    else need_1 = true;
    for (int i = 0; i < 2; i++) {
        int costp = 0;
        int n0, n1, np;
        costp = pairPrice[i];
        if (i > 0) {
            np = max(p, 4);
        } else np = p;
       
        for (int a : {0, 1, 3, 5}){
            int costa = price[a];
            for (int b : {0, 1, 3, 5}){
                n0 = max(r0, a);
                n1 = max(r1, b);
                int costb = price[b];
                if (n0 == 0 && need_0 && np == 0) continue;
                if (n1 == 0 && need_1 && np == 0) continue;
                
                n0 = max(n0 - 1, 0);
                n1 = max(n1 - 1, 0);
                np = max(np - 1, 0);
                dp[day][r0][r1][p] = min(dp[day][r0][r1][p], dfs(day + 1, n0, n1, np) + costa + costb + costp);
            }
        }
    }
    return dp[day][r0][r1][p];
}



int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << dfs(0, 0, 0, 0);
}