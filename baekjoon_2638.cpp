#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[101][101];
int visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int tm = 0;
int cheese = 1;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
}

void dfs(int xpos, int ypos){
    if (visited[xpos][ypos] == -1) visited[xpos][ypos]--;
    for (int i = 0; i < 4; i++){
        int nx = xpos + dx[i];
        int ny = ypos + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m){
            continue;
        } else if (graph[nx][ny] == 1){
            int cnt = 0;
            cheese++;
            for (int j = 0; j < 4; j++){
                int nnx = nx + dx[j];
                int nny = ny + dy[j];
                if (visited[nnx][nny] == -1 || visited[nnx][nny] == -2) cnt++;
            }
            if (cnt >= 2) visited[nx][ny] = 2;
        } else if (graph[nx][ny] == 0){
            if (visited[nx][ny] == -1) dfs(nx, ny);
        }
    }
}

void setVisited(int xpos, int ypos){
    if (visited[xpos][ypos] == 0) visited[xpos][ypos] = -1;
    for (int i = 0; i < n; i++){
        int nx = xpos + dx[i];
        int ny = ypos + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (visited[nx][ny] == 0) setVisited(nx, ny);
        }
    }
}

void solve(){
    while (cheese != 0){
        cheese = 0;
        tm ++;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] == 2){
                    graph[i][j] = 0;
                }
                visited[i][j] = graph[i][j];        
            }
        }
        setVisited(0, 0); // set external air -1
        dfs(0, 0);
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    cout << tm -1;
}