#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_set>

using namespace std;

int n, m;
int dp[102][102]; 
bool rest[101];
int ans = INT_MAX;

void input(){
    cin >> n >> m;
    memset(rest, false, 101);
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        rest[a] = true;
    }
}


int dfs(int day, int coupon){
    if (day > n) return 0;
    if (dp[day][coupon] != 1000001) {
        return dp[day][coupon];
    }
    if (rest[day]) {
        dp[day][coupon] = dfs(day + 1, coupon);
        return dp[day][coupon];
    }
    if (coupon >= 3) dp[day][coupon] = min(dp[day][coupon], dfs(day + 1, coupon -3));
    dp[day][coupon] = min(dp[day][coupon], dfs(day + 1, coupon) + 10000);
    dp[day][coupon] = min(dp[day][coupon], dfs(day + 3, coupon + 1) + 25000);
    dp[day][coupon] = min(dp[day][coupon], dfs(day + 5, coupon + 2) + 37000);   
    return dp[day][coupon];
}

void sol(){
    input();
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 101; j++) dp[i][j] = 1000001;
    }
    cout << dfs(1, 0);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}