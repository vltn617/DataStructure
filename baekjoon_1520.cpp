#include <iostream>
using namespace std;

int n, m;
int graph[501][501];
int dp[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (graph[nx][ny] < graph[x][y]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << "\n";
}
