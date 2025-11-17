#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[9][9];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;
int tempGraph[9][9];
vector <pair<int, int>> pos;
vector <pair<int, int>> virus;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
            pos.push_back({i, j});
            if (graph[i][j] == 2) virus.push_back({i, j});
        }
    }
}

void dfs(int x, int y){
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        else if (tempGraph[nx][ny] == -1) continue;
        else if (tempGraph[nx][ny] == 0) {
            tempGraph[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

void sol(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (graph[i][j] == 2) graph[i][j] = 1;       // virus
            else if (graph[i][j] == 1) graph[i][j] = -1; // wall
            else if (graph[i][j] == 0) graph[i][j] = 0; // unvisited;
        }
    }
    for (pair<int, int> pi1 : pos){
        for (pair<int, int> pi2 : pos){
            for (pair<int ,int> pi3 : pos){
                if (pi1 == pi2 || pi2 == pi3 || pi1 == pi3) continue;
                if (graph[pi1.first][pi1.second] != 0) continue;
                if (graph[pi2.first][pi2.second] != 0) continue;
                if (graph[pi3.first][pi3.second] != 0) continue;

                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++) tempGraph[i][j] = graph[i][j];
                }
                tempGraph[pi1.first][pi1.second] = -1;
                tempGraph[pi2.first][pi2.second] = -1;
                tempGraph[pi3.first][pi3.second] = -1;
                for (pair <int, int> pi : virus){
                    dfs(pi.first, pi.second);
                }
                int cnt = 0;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        if (tempGraph[i][j] == 0) cnt++; 
                    }
                }
                ans = max(ans, cnt);
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
    cout << ans;
}