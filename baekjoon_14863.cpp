#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, Time;
vector <pair <int, int>> walk;
vector <pair <int, int>> bike;
long long dp[110][100001];

long long MAX(long long a, long long b){
    if (a > b) return a;
    else return b;
}

void input(){
    cin >> n >> Time;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        walk.push_back({a, b});
        bike.push_back({c, d});
        
    }
}

int dfs(int loc, int tm){
    if (tm < 0) return INT_MIN;
    if (loc >= n) return 0;
    if (dp[loc][tm] != -1) return dp[loc][tm];
    dp[loc][tm] = MAX(dfs(loc + 1, tm - bike[loc].first) + bike[loc].second, dfs(loc + 1, tm - walk[loc].first) + walk[loc].second);
    return dp[loc][tm];
}

void sol(){
    input();
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= Time; j++) dp[i][j] = -1;
    }
    cout << dfs(0, Time);
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    sol();
}