#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int startx, starty, endx, endy;
int graph[301][301];
int dist[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin >> n >> m >> startx >> starty >> endx >> endy;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            char a;
            cin >> a;
            if (a == '#') a = '0';
            else if (a == '*') a = '1';
            graph[i][j] = (int) a - 48;
            dist[i][j] = INT_MAX;
        }
    }
}

void sol(){
    dist[startx][starty] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, startx, starty});
    while (!pq.empty()){
        auto[d, x, y] = pq.top();   
        pq.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (dist[nx][ny] > dist[x][y] + graph[x][y]){
                dist[nx][ny] = dist[x][y] + graph[x][y];
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    cout << dist[endx][endy];
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}