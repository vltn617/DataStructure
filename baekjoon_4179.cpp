#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

char map[1001][1001];
int n, m;
int graph[1001][1001];
int route[1001][1001];
queue<tuple<int, int, int>> fire; // xpos ypos time
queue<tuple<int, int, int>> excape;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = INT_MAX;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            graph[i][j] = INT_MAX;
            route[i][j] = INT_MAX;
            cin >> map[i][j];
            if (map[i][j] == 'F') {
                fire.push({i, j, 0});
                graph[i][j] = 0;
            }
            else if (map[i][j] == '#') graph[i][j] = -1;
            else if (map[i][j] == 'J') {
                excape.push({i, j, 0});
                route[i][j] = 0;
            }
        }
    }
}

void bfs(){
    while (!fire.empty()){
        auto[x, y, t] = fire.front();
        fire.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (graph[nx][ny] == -1) continue;
            if (graph[nx][ny] > t + 1){
                graph[nx][ny] = t + 1;
                fire.push({nx, ny, t + 1});
            } 
        }
    }
}

void sol(){
    bfs();
    while (!excape.empty()){
        auto[x, y, t] = excape.front();
        excape.pop();
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) ans = min(ans, t + 1);
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (graph[nx][ny] == -1) continue;
            if (graph[nx][ny] <= t + 1) continue;
            if (route[nx][ny] > t + 1){
                route[nx][ny] = t + 1;
                excape.push({nx, ny, t + 1});
            }
        }
    }
    if (ans == INT_MAX) cout << "IMPOSSIBLE";
    else cout << ans;
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}