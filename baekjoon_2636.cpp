#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int graph[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int tm;
int cnt = 1;
int visited[101][101];

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

void dfs(int xpos, int ypos){
    if (visited[xpos][ypos] == 0) visited[xpos][ypos]--;
    for (int i = 0; i < 4; i++){
        int nx = xpos + dx[i];
        int ny = ypos + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // out or range
        else if (visited[nx][ny] == 1){
            graph[nx][ny] = 0;
            visited[nx][ny] = 2;
            cnt ++;
        } else if (visited[nx][ny] == 0){
            dfs(nx, ny);
        }
    }
}

void solve(){
    int lastCheese = 0;
    while (cnt != 0){
        tm++;
        cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                visited[i][j] = graph[i][j];
            }
        }
        dfs(0, 0);
        if (cnt != 0) lastCheese = cnt;
    }
    cout << tm -1 << '\n' << lastCheese;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    solve();
}