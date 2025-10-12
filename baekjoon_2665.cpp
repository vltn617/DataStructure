#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n;
int graph[51][51];
int visited[51][51] = {-1,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char a;
            cin >> a;
            graph[i][j] = a - '0';
            graph[i][j] =  1 - graph[i][j];
            visited[i][j] = -1;
        }
    }
}

int bfs(){
    queue <tuple <int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0] = 0;
    while (!q.empty()){
        auto [xpos, ypos, cnt] = q.front();
        q.pop();
        visited[xpos][ypos] = cnt;
        for (int i = 0; i < 4 ; i++){
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n){
                continue;
            } else if (graph[nx][ny] == 1){
                if (cnt + 1 < visited[nx][ny]){
                    q.push({nx, ny, cnt + 1});
                }
            } else{
                if (visited[nx][ny] == -1 || visited[nx][ny] > cnt) q.push({nx, ny, cnt});
            }
        }
    }
    return visited[n-1][n-1];
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    cout << bfs() << '\n';
    return 0;
}