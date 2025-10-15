#include <iostream>
#include <vector>
#include <algorithm>    
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

int n;
int graph[1001][1001];
int dist[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
            dist[i][j] = INT_MAX;
        }
    }
}

void sol(){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    while (!pq.empty()){
        auto[d, x, y] = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] > max(dist[x][y], abs(graph[nx][ny] - graph[x][y]))){
                dist[nx][ny] = max(dist[x][y], abs(graph[nx][ny] - graph[x][y]));
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
    
    cout << dist[n-1][n-1];
}