#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector <int> r;
vector <int> l;
int dp[2001][2001];

void input(){
    cin >> n; 
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        l.push_back(a);
    }
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        r.push_back(a);
    }
}
int dfs(int lidx, int ridx){
    if (lidx > n - 1 || ridx > n - 1) {
        return 0;
    }
    if (dp[lidx][ridx] != -1) return dp[lidx][ridx];
    if (l[lidx] <= r[ridx]){
        dp[lidx][ridx] = max(dfs(lidx + 1, ridx + 1), dfs(lidx + 1, ridx));
    } else {
        dp[lidx][ridx] = dfs(lidx, ridx + 1) + r[ridx];
    }
    return dp[lidx][ridx];
}

void sol(){
    input();
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}


int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}
