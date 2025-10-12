#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int n, m;
int graph[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int wall[101][101];

void input(){
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char a;
            cin >> a;
            graph[i][j] = (int) a - 48;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            wall[i][j] = INT_MAX;
        }
    }
}

void sol(){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0});
    wall[0][0] = 0;
    while (!pq.empty()){
        auto[cost, x, y] = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 ||  nx >= n || ny < 0 || ny >= m) continue;
            if (wall[nx][ny] <= cost + graph[nx][ny]) continue;
            wall[nx][ny] = cost + graph[nx][ny];
            pq.push({wall[nx][ny], nx, ny});
        }
    }
    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << wall[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << wall[n - 1][m - 1];
}

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    input();
    sol();
}