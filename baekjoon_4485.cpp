#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main(){
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int graph[126][126];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n = -1;
    int idx = 0;
    while (n != 0){
        cin >> n;
        if (n == 0) break;
        idx ++;
        int dist[126][126];
        priority_queue<tuple<int, int, int>, vector <tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> graph[i][j];
                dist[i][j] = INT_MAX;
            }
        }

        dist[0][0] = graph[0][0];
        pq.push({0, 0, 0});
        while (!pq.empty()){
            auto[cost, xpos, ypos] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++){
                int nx = xpos + dx[i];
                int ny = ypos + dy[i];
                if (nx < 0 || nx >= n || ny < 0 ||  ny >= n) continue;
                if (dist[nx][ny] > dist[xpos][ypos] + graph[nx][ny]){
                    dist[nx][ny] = dist[xpos][ypos] + graph[nx][ny];
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }

        cout << "Problem " << idx << ": " << dist[n-1][n-1] << "\n";
    }
}